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
RUN curl -LOk https://github.com/bazelbuild/bazel/releases/download/0.28.1/bazel-0.28.1-installer-linux-x86_64.sh && \
	chmod +x bazel-0.28.1-installer-linux-x86_64.sh && \
	./bazel-0.28.1-installer-linux-x86_64.sh --user
RUN /bin/sh build.sh
CMD ["/bin/sh", "run.sh"]
EXPOSE 8080