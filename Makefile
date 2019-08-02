PROTOC=dep/protobuf/bin/protoc
PROTOS_PATH=protos/
GRPC_OUT=include/protobuf/
GRPC_CPP_PLUGIN_PATH=dep/grpc/bin/grpc_cpp_plugin
GRPC_NODE_PLUGIN_PATH=dep/grpc/bin/grpc_node_plugin
PROTO_IN=protos/*.proto

release:
	sh scripts/build.sh
docker:
	docker build -t heiseish/dawnai:v1.0.0 -f Dockerfile .

opencv:
	sh scripts/install_opencv.sh
grpc:
	sh scripts/grpc.sh

protobuf:
	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=$(GRPC_OUT) \
	--plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) \
	$(PROTO_IN)
	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=$(GRPC_OUT) \
	--plugin=protoc-gen-grpc=$(GRPC_NODE_PLUGIN_PATH) \
	$(PROTO_IN)
	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=$(GRPC_OUT) $(PROTO_IN)

dependency-graph:
	xdot <(bazel query --nohost_deps --noimplicit_deps 'deps(//src:Dawn)' --output graph)

bazel:
	bazel build //src:server \
		--incompatible_depset_is_not_iterable=false \
    	--jobs 8