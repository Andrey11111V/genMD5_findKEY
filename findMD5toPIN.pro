TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        avt.cpp \
    generatemd5.cpp \
        main.cpp \
        md5.cpp \
    readfile.cpp

HEADERS += \
    avt.h \
    generatemd5.h \
    global.h \
    md5.h \
    readfile.h \
    struct_frame.h
