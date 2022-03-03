cmake -B ./build/Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Debug -G "Ninja"

ninja -C ./build/Debug

./build/Debug/Sandbox
read
