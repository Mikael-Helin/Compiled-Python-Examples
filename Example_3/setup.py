from setuptools import setup, Extension
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "mylib",
        ["mylib.cc"],
        include_dirs=["/usr/lib/armadillo"],  # Adjust this path if necessary
        libraries=["armadillo"],
        extra_compile_args=["-std=c++11"],
    ),
]

setup(
    name="mylib",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
)