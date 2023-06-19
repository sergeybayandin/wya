QT     += core widgets network websockets
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

# gui/dialog
HEADERS +=                                \
    include/gui/dialog/groupchatdialog.h  \
    include/gui/dialog/friendchatdialog.h

SOURCES +=                              \
    src/gui/dialog/groupchatdialog.cpp  \
    src/gui/dialog/friendchatdialog.cpp

# gui/box
HEADERS +=                                  \
    include/gui/box/creategroupbox.h        \
    include/gui/box/groupbox.h              \
    include/gui/box/globalsearchgroupbox.h  \
    include/gui/box/messagebox.h            \
    include/gui/box/friendbox.h             \
    include/gui/box/globalsearchfriendbox.h \
    include/gui/box/incominginvitebox.h     \
    include/gui/box/outgoinginvitebox.h
    
SOURCES +=                                \
    src/gui/box/creategroupbox.cpp        \
    src/gui/box/groupbox.cpp              \
    src/gui/box/globalsearchgroupbox.cpp  \
    src/gui/box/messagebox.cpp            \
    src/gui/box/friendbox.cpp             \
    src/gui/box/globalsearchfriendbox.cpp \
    src/gui/box/incominginvitebox.cpp     \
    src/gui/box/outgoinginvitebox.cpp
    
# core
HEADERS +=                      \
    include/core/serverconfig.h \
    include/core/user.h
    
SOURCES +=                    \
    src/core/serverconfig.cpp \
    src/core/user.cpp

# core/user
HEADERS +=                             \
    include/core/user/group.h          \
    include/core/user/friend.h         \
    include/core/user/incominginvite.h \
    include/core/user/outgoinginvite.h

SOURCES +=                           \
    src/core/user/group.cpp          \
    src/core/user/friend.cpp         \
    src/core/user/incominginvite.cpp \
    src/core/user/outgoinginvite.cpp

# core/types
HEADERS +=                      \
    include/core/types/action.h

# ui/widget
FORMS +=                          \
    ui/widget/friendstabwidget.ui \
    ui/widget/groupstabwidget.ui  \
    ui/widget/authwidget.ui       \
    ui/widget/wyawidget.ui        \
    ui/widget/lobbywidget.ui
    
# ui/box
FORMS +=                            \
    ui/box/creategroupbox.ui        \
    ui/box/groupbox.ui              \
    ui/box/globalsearchgroupbox.ui  \
    ui/box/messagebox.ui            \
    ui/box/friendbox.ui             \
    ui/box/globalsearchfriendbox.ui \
    ui/box/incominginvitebox.ui     \
    ui/box/outgoinginvitebox.ui

# ui/dialog
FORMS +=                          \
    ui/dialog/groupchatdialog.ui  \
    ui/dialog/friendchatdialog.ui
