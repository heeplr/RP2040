mkdir build
cd build
PICO_SDK_PATH=/opt/pico-sdk cmake ..
make
cp *.uf2 /run/media/daniel/RPI-RP2
