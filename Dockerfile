FROM heiseish/dawn_base:v1.0.0
WORKDIR /home

COPY dep dep
COPY protos protos

COPY scripts scripts
COPY Makefile Makefile
COPY 3rdparty_buildfiles 3rdparty_buildfiles
COPY src src
COPY WORKSPACE WORKSPACE
COPY run.sh run.sh
COPY build.sh build.sh
COPY .bazelrc .bazelrc
# RUN /bin/sh build.sh
RUN pip install mkl mkl-include
CMD ["/bin/sh", "run.sh"]
EXPOSE 8080