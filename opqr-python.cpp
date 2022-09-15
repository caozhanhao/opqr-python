//   Copyright 2022 opqr-python - caozhanhao
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
#include <Python.h>
#include <structmember.h>
#include "opqr/include/opqr/opqr.hpp"

struct PyQRObject
{
  PyObject_HEAD
  opqr::QR *qr = nullptr;
};
static void *PyQR_dealloc(PyObject *obj)
{
  delete ((PyQRObject *)obj)->qr;
  Py_TYPE(obj)->tp_free(obj);
  return nullptr;
}
inline opqr::QR *ParseQR(PyObject *obj) 
{
  return ((PyQRObject *)obj)->qr;
}

inline PyObject *ReturnQR(opqr::QR *m, PyTypeObject *type) 
{
  PyQRObject *obj = PyObject_NEW(PyQRObject, type);
  obj->qr = m;
  return (PyObject *)obj;
}

PyObject *PyQR_image(PyObject *self, PyObject *args, PyObject *kw)
{
  PyQRObject *obj = (PyQRObject *)self;
  char *path;
  int ext = -1;
  int size = -1;
  char *kwlist[] = { (char *)"path", (char *)"ext", (char *)"size", NULL};
  if (!PyArg_ParseTupleAndKeywords(args, kw, "s|ii", kwlist, &path, &ext, &size))
  {
    return nullptr;
  }
  std::ofstream fs(path);
  if (size == -1) size = 10;
  if(ext == 1)
    obj->qr->generate().paint(opqr::pic::Format::PPM, fs, size);
  else//0 or -1
    obj->qr->generate().paint(opqr::pic::Format::BMP, fs, size);
  return self;
}

static PyMethodDef QRMethods[]
{
    {"image", (PyCFunction)PyQR_image, METH_VARARGS | METH_KEYWORDS, 
    "|  Generate a image.\n"
    "|\n"
    "|  Arguments:\n"
    "|    path : a path to write the image.\n"
    "|  optional:\n"
    "|    ext  : the file extension.                           [default] bmp [0] bmp [1] ppm\n"
    "|    size : the image's size = version's dimension * size [default] 10\n"
  },
    {nullptr} 
};

static PyTypeObject QRType
{
    PyVarObject_HEAD_INIT(nullptr, 0) "opqr.QR",       /* tp_name */
    sizeof(PyQRObject),                                /* tp_basicsize */
    0,                                                 /* tp_itemsize */
    (destructor)PyQR_dealloc,                          /* tp_dealloc */
    0,                                                 /* tp_print */
    nullptr,                                           /* tp_getattr */
    nullptr,                                           /* tp_setattr */
    nullptr,                                           /* tp_reserved */
    nullptr,                                           /* tp_repr */
    nullptr,                                           /* tp_as_number */
    nullptr,                                           /* tp_as_sequence */
    nullptr,                                           /* tp_as_mapping */
    nullptr,                                           /* tp_hash  */
    nullptr,                                           /* tp_call */
    nullptr,                                           /* tp_str */
    nullptr,                                           /* tp_getattro */
    nullptr,                                           /* tp_setattro */
    nullptr,                                           /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,          /* tp_flags */
    "QR encoder.",                                     /* tp_doc */
    nullptr,                                           /* tp_traverse */
    nullptr,                                           /* tp_clear */
    nullptr,                                           /* tp_richcompare */
    0,                                                 /* tp_weaklistoffset */
    nullptr,                                           /* tp_iter */
    nullptr,                                           /* tp_iternext */
    QRMethods,                                         /* tp_methods */
    nullptr,                                           /* tp_members */
    nullptr,                                           /* tp_getset */
    nullptr,                                           /* tp_base */
    nullptr,                                           /* tp_dict */
    nullptr,                                           /* tp_descr_get */
    nullptr,                                           /* tp_descr_set */
    0,                                                 /* tp_dictoffset */
    nullptr,                                           /* tp_init */
    nullptr,                                           /* tp_alloc */
    nullptr                                            /* tp_new */
};

static PyObject *PyQR_encode(PyObject *self, PyObject *args, PyObject *kw)
{
  char *data;
  int mode = -1;
  int level = -1;
  int version = -1;
  int mask = -1;
  char *kwlist[] = { (char *)"data", (char *)"level", (char *)"mode", (char *)"version", (char *)"mask", NULL };
  if (!PyArg_ParseTupleAndKeywords(args, kw, "s|iiii", kwlist, &data, &level, &mode, &version, &mask))
  {
    return nullptr;
  }
  opqr::QR *qr = new opqr::QR();
  if (mode != -1)
    qr->set_mode(opqr::to_mode(mode));
  if (level != -1)
    qr->set_level(opqr::to_ecl(level));
  if (version != -1)
    qr->set_version(version);
  if (mask != -1)
    qr->set_mask(mask);
  qr->add_data(data);
  return ReturnQR(qr, &QRType);
}

static PyMethodDef opqrMethods[]
{
    {"encode", (PyCFunction)PyQR_encode, METH_VARARGS | METH_KEYWORDS, 
    "|  Encode given data.\n"
    "|\n"
    "|  Arguments:\n"
    "|    data    : a string to be encoded.\n"
    "|  optional:\n"
    "|    version : the QR code's version. int  [1,40]\n"
    "|    mode    : the encoding mode.          [0] Num [1] Alnum [2] 8-Bit [3] Kanji\n"
    "|    level   : the error correcting level. [0] L   [1] M     [2] Q     [3] H\n"
    "|    mask    : the QR code's mask.         [0,7]\n"
    },
    {nullptr}
};
static struct PyModuleDef module
{
    PyModuleDef_HEAD_INIT,
    "opqr",
    "A Simple QR encode Library.",
    -1,
    opqrMethods
};

PyObject *initModule(void)
{
  PyObject *m;
  if (PyType_Ready(&QRType) < 0)
    return nullptr;

  m = PyModule_Create(&module);
  if (m == nullptr)
    return nullptr;

  Py_INCREF(&QRType);
  if (PyModule_AddObject(m, "QR", (PyObject *)&QRType) < 0)
  {
    Py_DECREF(&QRType);
    Py_DECREF(m);
    return nullptr;
  }
  return m;
}
