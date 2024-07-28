TEMPLATE = app
QT += core gui widgets svg xml
CONFIG += c++11

TARGET = qrwemotions

HEADERS += \
    src/MainWindow.h \
    src/QrwEmoticons_p.h \
    src/QrwEmoticons \
    src/QrwEmoticonsTextObjectInterface_p.h  \
    src/Global.h \
    src/QrwEmoticons.h \
    src/QrwEmoticonsPlugin.h \
    src/TextEdit.h \
    src/QrwEmoticonsHelper.h

SOURCES += \
    src/MainWindow.cpp \
    src/QrwEmoticons_data.cpp \
    src/QrwEmoticons.cpp \
    src/QrwEmoticons_p.cpp \
    src/QrwEmoticonsTextObjectInterface.cpp \
    src/TextEdit.cpp \
    src/QrwEmoticonsHelper.cpp \
    src/main.cpp
