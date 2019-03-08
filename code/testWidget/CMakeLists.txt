cmake_minimum_required(VERSION 2.8)

project(testWidget)


find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(${PROJECT_NAME} "main.cpp" "range_image_widget.cpp" "range_image_widget.ui" "form.cpp" "form.ui" "rangeimagewidget.cpp")
target_link_libraries (${PROJECT_NAME}  ${PCL_LIBRARIES})
