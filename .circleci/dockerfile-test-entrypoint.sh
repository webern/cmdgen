#! /bin/bash
set -e

sep() {
    echo "----------------------------------------------------------------"
}

sep
echo "version info"
g++ --version
cmake --version
cat /etc/os-release
cd src

sep
cmake \
    -DCMDGEN_ENABLE_TESTS=on \
    .

sep
make -j 6

sep
echo "running tests"
./cmdgen_test
echo "success"

echo ""
echo "done running script - success"
exit 0
