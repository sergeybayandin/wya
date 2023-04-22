QT     += core widgets network
CONFIG += c++1z

INCLUDEPATH += include/

# main
SOURCES += src/main.cpp

# gui/widget
HEADERS +=                                \
    include/gui/widget/friendstabwidget.h \
    include/gui/widget/groupstabwidget.h  \
    include/gui/widget/authwidget.h       \
    include/gui/widget/wyawidget.h        \
    include/gui/widget/lobbywidget.h

SOURCES +=                              \
    src/gui/widget/authwidget.cpp       \
    src/gui/widget/wyawidget.cpp        \
    src/gui/widget/lobbywidget.cpp      \
    src/gui/widget/friendstabwidget.cpp \
    src/gui/widget/groupstabwidget.cpp

# gui/box
HEADERS +=                           \
    include/gui/box/creategroupbox.h \
    include/gui/box/groupbox.h
    
SOURCES +=                         \
    src/gui/box/creategroupbox.cpp \
    src/gui/box/groupbox.cpp
    
# core
HEADERS +=                      \
    include/core/serverconfig.h \
    include/core/user.h
    
SOURCES +=                    \
    src/core/serverconfig.cpp \
    src/core/user.cpp

# core/user
HEADERS +=                     \
    include/core/user/group.h  \
    include/core/user/friend.h

SOURCES +=                   \
    src/core/user/group.cpp  \
    src/core/user/friend.cpp

# ui/widget
FORMS +=                          \
    ui/widget/friendstabwidget.ui \
    ui/widget/groupstabwidget.ui  \
    ui/widget/authwidget.ui       \
    ui/widget/wyawidget.ui        \
    ui/widget/lobbywidget.ui
    
# ui/box
FORMS +=                     \
    ui/box/creategroupbox.ui \
    ui/box/groupbox.ui
