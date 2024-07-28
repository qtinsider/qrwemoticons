cmake_minimum_required(VERSION 3.16)

# Set the project name and version
project(qrwemotions VERSION 0.0.1 LANGUAGES CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable automatic processing of Qt MOC, UIC, and RCC files
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find the Qt6 package
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Svg Xml)

# Add the executable
add_executable(${PROJECT_NAME}
    src/MainWindow.cpp
    src/QrwEmoticons_data.cpp
    src/QrwEmoticons.cpp
    src/QrwEmoticons_p.cpp
    src/QrwEmoticonsTextObjectInterface.cpp
    src/TextEdit.cpp
    src/QrwEmoticonsHelper.cpp
    src/main.cpp
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Link Qt6 libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Svg Qt6::Xml)

# Add header files
target_sources(${PROJECT_NAME} PRIVATE
    src/MainWindow.h
    src/QrwEmoticons_p.h
    src/QrwEmoticons.h
    src/QrwEmoticonsTextObjectInterface_p.h
    src/Global.h
    src/QrwEmoticonsPlugin.h
    src/TextEdit.h
    src/QrwEmoticonsHelper.h
)



