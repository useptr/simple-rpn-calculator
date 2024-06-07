QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../calculator/calculator.cc \
    ../calculator/credit_calculator.cc \
    ../calculator/validator.cc \
    ../calculator/operator_factory.cc \
    ../calculator/token.cc \
    ../calculator/tokenizer.cc \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../calculator/calculator.h \
    ../calculator/credit_calculator.h \
    ../calculator/validator.h \
    ../calculator/operator_factory.h \
    ../calculator/token.h \
    ../calculator/tokenizer.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
