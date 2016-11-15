# README.md

add the path to {/ndk/root/folder} and {/android/sdk/root/folder}/platform-tools to the $PATH environment variable

$ ndk-build APP_ABI=armeabi-v7a
[armeabi-v7a] Compile++ thumb: test-boost <= test.cpp
[armeabi-v7a] Compile++ thumb: test-boost <= gps.cpp
[armeabi-v7a] Prebuilt       : libgnustl_shared.so <= <NDK>/sources/cxx-stl/gnu-libstdc++/4.9/libs/armeabi-v7a/thumb/
[armeabi-v7a] Executable     : test-boost
[armeabi-v7a] Prebuilt       : libboost_atomic.so <= <NDK>/sources/boost/1.57.0/libs/armeabi-v7a/
[armeabi-v7a] Install        : libcrystax.so => libs/armeabi-v7a/libcrystax.so
[armeabi-v7a] Install        : test-boost => libs/armeabi-v7a/test-boost
[armeabi-v7a] Install        : libgnustl_shared.so => libs/armeabi-v7a/libgnustl_shared.so

$ adb push libs/armeabi-v7a/libcrystax.so /data/local/tmp
1231 KB/s (537036 bytes in 0.425s)

$ adb push libs/armeabi-v7a/libgnustl_shared.so /data/local/tmp
1234 KB/s (718448 bytes in 0.568s)

$ adb push libs/armeabi-v7a/test-boost /data/local/tmp
840 KB/s (50536 bytes in 0.058s)

$ adb shell 'cd /data/local/tmp && LD_LIBRARY_PATH=/data/local/tmp ./test-boost'
Initial value: GPS(35/59/24.567)
After load: GPS(35/59/24.567)
Congratulations! GPS object was successfully saved and then loaded