all: flask

flask:
	java -jar ~/Applications/openapi-generator-cli.jar generate -i api.yaml -g python-flask -o ../backend && \
	java -jar ~/Applications/openapi-generator-cli.jar generate -i api.yaml -g javascript -o ../html/js