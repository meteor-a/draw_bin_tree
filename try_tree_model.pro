QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FindTree.cpp \
    ITree.cpp \
    RedBlackTree.cpp \
    avl_tree.cpp \
    dialogeditadd.cpp \
    dialogerror.cpp \
    dialogsetrange.cpp \
    displayavltree.cpp \
    displayfindtree.cpp \
    displayredblacktree.cpp \
    displaytwotreetree.cpp \
    graphicellipsecustom.cpp \
    graphviewcustom.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    CNode.h \
    CTree.h \
    CTreeError.h \
    FindTree.h \
    ITree.h \
    RedBlackTree.h \
    TypeShowAvlTree.h \
    avl_tree.h \
    dialogeditadd.h \
    dialogerror.h \
    dialogsetrange.h \
    displayavltree.h \
    displayfindtree.h \
    displayredblacktree.h \
    displaytwotreetree.h \
    graphicellipsecustom.h \
    graphviewcustom.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    dialogeditadd.ui \
    dialogerror.ui \
    dialogsetrange.ui
