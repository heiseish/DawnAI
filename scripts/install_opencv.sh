cv dep/
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
cd opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE \
		-D CMAKE_INSTALL_PREFIX=dep/opencv4 \
		-D WITH_TBB=ON \
		-D WITH_V4L=ON \
		-D GLIBCXX_USE_CXX11_ABI=1 \
		-D WITH_QT=ON \
		-D WITH_OPENGL=ON \
		-D OPENCV_EXTRA_MODULES_PATH=opencv_contrib/modules ..
make -j8
make install