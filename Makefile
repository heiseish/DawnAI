local:
	sh build_local.sh
docker:
	docker build -t heiseish/dawnai:v1.0.0 -f Dockerfile .