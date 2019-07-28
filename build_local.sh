rm -rf build
rm -rf output

mkdir -p build
cd build
cmake -G Ninja -D CMAKE_BUILD_TYPE=Release -D BUILD_LOCAL=ON \
    -D CMAKE_C_COMPILER=/usr/local/Cellar/llvm/8.0.0_1/bin/clang \
    -D CMAKE_CXX_COMPILER=/usr/local/Cellar/llvm/8.0.0_1/bin/clang++ .. 
ninja -j8
cd ..
mv build/src/Dawn Dawn
mv build/test/Test Test

rm -rf build/