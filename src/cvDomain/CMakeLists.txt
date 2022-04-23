set(SRC_CV    IFrameReceiver.hpp
              FrameSourcesReceiver.hpp
              CameraFramesReceiver.hpp
              CameraFramesReceiver.cpp
              FrameSourcesReceiver.cpp
              Enums.hpp
              Constants.hpp)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_library( cvDom ${SRC_CV} )
target_link_libraries( cvDom ${OpenCV_LIBS} )
