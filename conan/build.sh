#!/bin/sh

function pause {
  echo "$1, press any key to continue..."
  read -n1
}

builddir=build/

rm -rf $builddir
mkdir $builddir
cd $builddir

pause "conan install"
conan install ..

pause "cmake build"
cmake ..
cmake --build .
