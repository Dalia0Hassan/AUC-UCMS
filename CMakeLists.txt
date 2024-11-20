cmake_minimum_required(VERSION 3.29)
project(UCMS)


include_directories(.)

add_executable(UCMS main.cpp
        headers/utils.h
        sources/utils.cpp

        headers/email.h
        sources/email.cpp

        headers/user.h
        sources/user.cpp

        sources/event.cpp
        headers/event.h

        sources/student.cpp
        headers/student.h
        headers/student.h
        admin.cpp
        admin.h

)



set(CMAKE_PREFIX_PATH "/Users/ayman/Qt/6.7.2/macos" CACHE STRING "Path to Qt6 installation")

# Find the required Qt6 packages, including Multimedia
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui Multimedia)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Link the Qt6 libraries to your executable, including Multimedia
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets Qt6::Gui Qt6::Multimedia)

# Include directories for Qt6
target_include_directories(${PROJECT_NAME} PRIVATE ${Qt6Core_INCLUDE_DIRS} ${Qt6Widgets_INCLUDE_DIRS} ${Qt6Gui_INCLUDE_DIRS} ${Qt6Multimedia_INCLUDE_DIRS})
