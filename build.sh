rm -rf build
rm -rf output

mkdir -p build
cd build
cmake -G Ninja -D CMAKE_BUILD_TYPE=Release -D .. 
ninja -j2
cd ..
mv build/src/Dawn Dawn
mv build/test/Test Test

rm -rf build/