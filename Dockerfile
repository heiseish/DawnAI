FROM victorhcm/opencv:3.1.0-python2.7

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
COPY dependencies dependencies
COPY cmake-3.15.0-Linux-x86_64.sh cmake-3.15.0-Linux-x86_64.sh

RUN mkdir /opt/cmake  && \
    sh cmake-3.15.0-Linux-x86_64.sh --prefix=/opt/cmake --skip-license \
    && ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake


WORKDIR /home
COPY src src
COPY build.sh build.sh
COPY test test
COPY include include
COPY logs logs
COPY CMakeLists.txt CMakeLists.txt
RUN sh build.sh
COPY serve.sh serve.sh

CMD ["./Dawn"]
EXPOSE 8080