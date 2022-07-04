######################################################################
# Automatically generated by qmake (3.1) Thu Jun 30 00:34:07 2022
######################################################################

TEMPLATE = app
TARGET = String_Pattern_Match
INCLUDEPATH += .

RC_ICONS = resources/SPM_logo_hot.ico

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += about.h batch1.h mainwindow.h patternMatch.h singlemode.h \
    batch1plot.h \
    batch2.h \
    batch2Plot.h
FORMS += about.ui batch1.ui mainwindow.ui singlemode.ui \
    batch1plot.ui \
    batch2.ui \
    batch2Plot.ui
SOURCES += about.cpp \
           batch1.cpp \
           batch1plot.cpp \
           batch2.cpp \
           batch2Plot.cpp \
           main.cpp \
           mainwindow.cpp \
           patternMatch.cpp \
           singlemode.cpp
QT += charts