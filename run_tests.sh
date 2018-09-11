git submodule update --init
mkdir build
cd build
cmake ..
make
cd tests
./ai_test