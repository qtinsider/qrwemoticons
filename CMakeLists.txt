cmake_minimum_required(VERSION 3.16)

# Set the project name and version
project(qrwemotions VERSION 0.0.1 LANGUAGES CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 23)
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

qt_add_resources(RESOURCES
    plugin-google/emoticons_google_0.qrc
    plugin-google/emoticons_google_1.qrc
    plugin-google/emoticons_google_2.qrc
    plugin-google/emoticons_google_3.qrc
    plugin-google/emoticons_google_4.qrc
    plugin-google/emoticons_google_5.qrc
    plugin-google/emoticons_google_6.qrc
    plugin-twitter/emoticons_twitter_0.qrc
    plugin-twitter/emoticons_twitter_1.qrc
    plugin-twitter/emoticons_twitter_2.qrc
    plugin-twitter/emoticons_twitter_3.qrc
    plugin-twitter/emoticons_twitter_4.qrc
    plugin-twitter/emoticons_twitter_5.qrc
    plugin-twitter/emoticons_twitter_6.qrc
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
    src/TextEdit.h
    src/QrwEmoticonsHelper.h
    ${RESOURCES}
)



