TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    figurageometrica.cpp \
    putbox.cpp \
    cutbox.cpp \
    putsphere.cpp \
    putvoxel.cpp \
    cutvoxel.cpp \
    putellipsoid.cpp \
    cutellipsoid.cpp \
    cutsphere.cpp

HEADERS += \
    figurageometrica.h \
    putbox.h \
    cutbox.h \
    putsphere.h \
    putvoxel.h \
    cutvoxel.h \
    putellipsoid.h \
    cutellipsoid.h \
    cutsphere.h
