#-------------------------------------------------
#
# Project created by QtCreator 2016-10-09T10:53:47
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = Project
TEMPLATE = app


SOURCES += main.cpp\
        view.cpp \
        model.cpp \
        controller.cpp \
        project.cpp \
    videosurface.cpp \
    convertimagethread.cpp \
    convertvideothread.cpp \
    mysubwindows.cpp

HEADERS  += view.h \
            model.h \
            controller.h \
            header.h \
            project.h \
            videosurface.h \
    playitem.h \
    convertimagethread.h \
    convertvideothread.h \
    mysubwindows.h

FORMS    += view.ui

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    icons/about.png \
    icons/help.png \
    icons/open.png \
    icons/photo_assemble.png \
    icons/photo_black_white.png \
    icons/redo.png \
    icons/save_as.png \
    icons/save.png \
    icons/undo.png
