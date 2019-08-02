# On ubuntu 18.04
sudo apt-get install -y build-essential autoconf libtool pkg-config automake curl

git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc
cd grpc
git submodule update --init
 
# Build and install protobuf
cd ./third_party/protobuf
./autogen.sh
./configure --prefix=/home/heiseish/Projects/DawnAI/dep/protobuf
make -j8
sudo make install
  
# Build and install gRPC
cd ../..
make -j8 PROTOC=/home/heiseish/Projects/DawnAI/dep/protobuf/bin/protoc
sudo make prefix=/home/heiseish/Projects/DawnAI/dep/grpc install