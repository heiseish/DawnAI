rm -rf build
rm -rf output

mkdir -p build
cd build
cmake -G Ninja -D CMAKE_BUILD_TYPE=Release \
	-D CMAKE_C_COMPILER=/usr/bin/gcc \
	-D CMAKE_CXX_COMPILER=/usr/bin/g++ .. 
ninja -j4
cd ..
mv build/src/Dawn Dawn
mv build/test/Test Test

rm -rf build/