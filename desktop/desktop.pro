QT     += core widgets network
CONFIG += c++1z

INCLUDEPATH += include/

# main
SOURCES += src/main.cpp

# gui
HEADERS +=              \
    include/gui/wyawidget.h

SOURCES +=                \
    src/gui/wyawidget.cpp

# core
HEADERS +=                      \
    include/core/serverconfig.h
    
SOURCES +=                    \
    src/core/serverconfig.cpp

# ui
FORMS += \
    ui/wyawidget.ui
