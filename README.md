# Sink源码概述
Miracast Sink端源码最早出现在`Android 4.2.2`上，通过googlesource可以很方便的查看：
[https://android.googlesource.com/platform/frameworks/av/+/android-4.2.2_r1.2/media/libstagefright/wifi-display/sink/](https://android.googlesource.com/platform/frameworks/av/+/android-4.2.2_r1.2/media/libstagefright/wifi-display/sink/ "https://android.googlesource.com/platform/frameworks/av/+/android-4.2.2_r1.2/media/libstagefright/wifi-display/sink/")

但是在`Android 4.3`以后，Google却移除掉了这部分源码，详细的commit记录在：
[https://android.googlesource.com/platform/frameworks/av/+/c4bd06130e4c3068ab58a0be88a4f765c2267563](https://android.googlesource.com/platform/frameworks/av/+/c4bd06130e4c3068ab58a0be88a4f765c2267563 "https://android.googlesource.com/platform/frameworks/av/+/c4bd06130e4c3068ab58a0be88a4f765c2267563")
```
Remove all traces of wifi display sink implementation and supporting code.

Change-Id: I64b681b7e3df1ef0dd80c0d261cacae293d5e684
related-to-bug: 8698812
```
虽然移除了Sink端代码，但是Source端源码是还在的，我们可以通过Android手机的投射功能实现Miracast投屏发送端。

# 导入源码
这里推荐使用Android Studio进行源码查看，为了方便使用IDE的代码提示及类/方法跳转等相关功能，我们需要搭建好源码环境。

1. 首先新建一个`Native Project`，然后把整个`libstagefright`相关的源码拷贝到cpp目录中，
![libstagefright目录源码](https://img2022.cnblogs.com/blog/835426/202207/835426-20220713163513990-1544713034.png)
我们可以直接点击tgz下载`libstagefright`相关的源码

2. include头文件也一起导入（因为涉及到很多依赖）

![image](https://img2022.cnblogs.com/blog/835426/202207/835426-20220713163743667-1289880780.png)

下载`android/platform/frameworks/native/refs/tags/android-4.2.2_r1.2/include`路径下的头文件

3. 然后在CMakeLists.txt中添加这部分源码。
```cmake

cmake_minimum_required(VERSION 3.10.2)

project("source")

include_directories(include)

file(GLOB_RECURSE source_file libstagefright/*.h libstagefright/*.cpp)

add_library(
             native-lib
             SHARED

            ${source_file})


find_library(
              log-lib
              log )

target_link_libraries(
                       native-lib
                       ${log-lib} )
```

4. 重新sync一次，这样就能引用到相关的类与头文件，并且支持代码提示，提高我们查看源码的效率。

![image](https://img2022.cnblogs.com/blog/835426/202207/835426-20220713164559830-1310353695.png)
















































