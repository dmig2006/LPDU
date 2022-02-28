TEMPLATE     = app
TARGET       = lmbdu

DESTDIR      = ./bin
VPATH       += ./gui ./include ./src ./resources ./i10n
INCLUDEPATH += ./include

MOC_DIR      = ./build/moc
OBJECTS_DIR  = ./build/objects
UI_DIR       = ./build/ui
RCC_DIR      = ./build/res

QT += gui core
QT += network
isEqual(QT_MAJOR_VERSION, 5) {
	QT += widgets
}

CONFIG += release

HEADERS += mainwindow.h \
           videowidget.h \
           client_tcp.h \
           parcels_irzcam.h \
           udp_server.h \
           validparceljpeg.h \
           optwidget.h \
           controllermanager.h \
           adjustment.h


FORMS +=   mainwindow.ui \
           videowidget.ui \
           optwidget.ui \
           adjustment.ui


SOURCES += main.cpp \
           mainwindow.cpp \
           videowidget.cpp \
           client_tcp.cpp \
           udp_server.cpp \
           validparceljpeg.cpp \
           optwidget.cpp \
           controllermanager.cpp \
           adjustment.cpp


RESOURCES = lmpdu_res.qrc

DISTFILES +=

