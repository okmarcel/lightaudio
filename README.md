# lightaudio
Project goal: a lightweight audio and DSP library in C, suited for embedded programming.
Status: work in progress

## Build
run
```
mkdir build
cd build
cmake ..
make install
```

## Using in project
In CMake add
```
find_package(lightaudio REQUIRED)
target_link_libraries(myapp PRIVATE lightaudio::lightaudio)
```
and in program file add
```
#include <lightaudio/lightaudio.h>
```

