cmake_minimum_required(VERSION 3.19)
project(gst_test LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Concurrent)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GSTREAMER REQUIRED
    gstreamer-1.0
    gstreamer-video-1.0
    gstreamer-app-1.0
)

include_directories(${GSTREAMER_INCLUDE_DIRS})
link_directories(${GSTREAMER_LIBRARY_DIRS})
add_definitions(${GSTREAMER_CFLAGS_OTHER})

qt_standard_project_setup()

qt_add_executable(gst_test
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    player.h player.cpp
    settings.h settings.cpp settings.ui
    playlist_manager.h playlist_manager.cpp
    mediaitem.h mediaitem.cpp
    playlist_view.h playlist_view.cpp
    playlist_delegate.h playlist_delegate.cpp
)

target_include_directories(gst_test PRIVATE ${GSTREAMER_INCLUDE_DIRS})

target_link_libraries(gst_test
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Concurrent
        ${GSTREAMER_LIBRARIES}
)

include(GNUInstallDirs)

install(TARGETS gst_test
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET gst_test
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
