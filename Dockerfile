FROM heiseish/dawn_base:v1.0.1
WORKDIR /home


COPY protos protos

COPY scripts scripts
COPY Makefile Makefile
COPY 3rdparty 3rdparty
COPY WORKSPACE WORKSPACE
COPY run.sh run.sh
COPY build.sh build.sh
COPY .bazelrc .bazelrc
COPY bazel-1.1.0-installer-linux-x86_64.sh bazel-1.1.0-installer-linux-x86_64.sh
RUN chmod +x bazel-1.1.0-installer-linux-x86_64.sh && \
	./bazel-1.1.0-installer-linux-x86_64.sh --user
COPY dep dep
COPY src src
RUN /bin/sh build.sh
CMD ["/bin/sh", "run.sh"]
EXPOSE 8080