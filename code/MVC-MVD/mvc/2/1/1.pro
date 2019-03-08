TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    application.cpp \
    views.cpp \
    controller.cpp

HEADERS += \
    application.h \
    observer.h \
    observable.h \
    model.h \
    titleview.h \
    versionview.h \
    creditsview.h \
    views.h \
    controller.h
