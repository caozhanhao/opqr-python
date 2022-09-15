#   Copyright 2022 opqr-python - caozhanhao
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
import os
import shlex
import subprocess
import datetime
import time
import shutil
from setuptools import setup, Extension

cwd = os.path.dirname(os.path.abspath(__file__))


def execute_command(cmdstring, cwd=None, timeout=None, shell=False):
    if shell:
        cmdstring_list = cmdstring
    else:
        cmdstring_list = shlex.split(cmdstring)
    if timeout:
        end_time = datetime.datetime.now() + datetime.timedelta(seconds=timeout)
    
    sub = subprocess.Popen(cmdstring_list, cwd=cwd, stdin=subprocess.PIPE,shell=shell,bufsize=4096)
    
    while sub.poll() is None:
        time.sleep(0.1)
        if timeout:
            if end_time <= datetime.datetime.now():
                raise Exception("Timeout: %s"%cmdstring)
        
    return sub.returncode

def build_library():
    config_command = "cmake -S {} -B {}"
    path_to_source = cwd
    path_to_build = os.path.join(cwd, "build")
    
    if os.path.exists(path_to_build):
        shutil.rmtree(path_to_build)
    config_command = config_command.format(path_to_source, path_to_build)
    
    code = execute_command(config_command)
    if code != 0:
        raise RuntimeError("Run configure command fail.")
    
    build_command = "cmake --build {}".format(os.path.join(cwd, "build"))
    code = execute_command(build_command)
    if code != 0:
        raise RuntimeError("Run build Command fail.")

def main():
    build_library()
    extention = Extension(
        "opqr",
        libraries=["opqr"],
        sources=["stub.cpp"],
        language="c++",
        extra_compile_args=['-std=c++17'],
        include_dirs=[cwd],
        library_dirs=[os.path.join(cwd, "build")]
    )
    setup(name="opqr",
          version="1.0.2",
          long_description="A Simple QR encode Library.",
          description="A Simple QR encode Library.",
          author="caozhanhao",
          author_email="cao2013zh@163.com",
          ext_modules=[extention]
    )


if __name__ == "__main__":
    main()
