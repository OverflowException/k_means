TEMPLATE = app
TARGET = k_means

DESTDIR = ./bin/
INCLUDEPATH += ./include/
SOURCEPATH += ./src/
OBJECTS_DIR += ./build
MOC_DIR = ./moc
VPATH += $$INCLUDEPATH $$SOURCEPATH

# Input
HEADERS += gausspointcluster.h \
           imagecontainer.h \
           mainwindow.h \
           visualizationwidget.h
SOURCES += gausspointcluster.cpp \
           imagecontainer.cpp \
           main.cpp \
           mainwindow.cpp \
           visualizationwidget.cpp

QT += widgets gui        
CONFIG += qt release
