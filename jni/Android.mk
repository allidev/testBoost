# Android.mk
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE           := test-boost
LOCAL_CPPFLAGS         += -D_GLIBCXX_USE_CXX11_ABI=0
LOCAL_SRC_FILES        := test.cpp gps.cpp
LOCAL_STATIC_LIBRARIES := boost_serialization_static boost_system_static boost_filesystem_static
# Or, if you need to link with Boost Serialization library dynamically:
#LOCAL_SHARED_LIBRARIES := boost_serialization_shared
include $(BUILD_EXECUTABLE)

$(call import-module,boost/1.59.0)