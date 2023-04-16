CONFIG += c++2a

INCLUDEPATH +=                          \
               include                  \
               third_party/crow/include
               
# main
SOURCES += src/main.cpp
               
# handler
HEADERS +=                             \
           include/handler/authorize.h \
           include/handler/register.h
           
SOURCES +=                           \
           src/handler/authorize.cpp \
           src/handler/register.cpp
