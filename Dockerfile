FROM ubuntu:latest

RUN apt-get update && apt-get install -y software-properties-common && \
    add-apt-repository -y ppa:ubuntu-toolchain-r/test && apt-get update && \
    apt-get install -y \
    build-essential \
    curl \
    gfortran \
    gcc-9\
    g++-9 \
    git \
    libboost-all-dev \
    libgtk2.0-dev \
    pkg-config \
	qt5-default \
    libavcodec-dev \
    libavformat-dev \
    libswscale-dev \
    python-dev \
    python-numpy \
    python-protobuf\
    zip \
    ninja-build \ 
    wget \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* && \
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 20 --slave /usr/bin/g++ g++ /usr/bin/g++-9

WORKDIR /home
COPY . .
RUN sh cmake-3.15.0-Linux-x86_64.sh --skip-license && make release
CMD ["./Dawn"]
EXPOSE 8080