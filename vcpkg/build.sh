#!/bin/sh

function pause {
  echo "$1, press any key to continue..."
  read -n1
}

builddir=build/

rm -rf $builddir
mkdir $builddir
cd $builddir

pause "cmake build"
cmake .. -DCMAKE_TOOLCHAIN_FILE=../../../vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
