THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
CMDGEN_DIR="$THIS_DIR/.."
cd "$THIS_DIR"

# docker build \
#     -f "$THIS_DIR/Dockerfile" \
#     -t matthewjamesbriggs/cmake:v001 \
#     "$THIS_DIR"

docker rm -f cmdgentestcontainer || true;
docker rmi -f cmdgentestimage || true;

docker build \
    -f "$THIS_DIR/Dockerfile.test" \
    -t cmdgentestimage \
    "$CMDGEN_DIR"

docker run -it --name cmdgentestcontainer cmdgentestimage