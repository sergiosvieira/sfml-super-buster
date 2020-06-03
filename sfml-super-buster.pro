TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "/usr/local/opt/sfml/include"
LIBS += -L"/usr/local/opt/sfml/lib"
LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

SOURCES += \
        event-manager.cpp \
        frame.cpp \
        game-manager.cpp \
        main.cpp \
        object.cpp \
        player.cpp

HEADERS += \
    any-callable.h \
    event-manager.h \
    event.h \
    frame.h \
    game-consts.h \
    game-header.h \
    game-manager.h \
    game-random.h \
    game-state.h \
    game-update.h \
    level.h \
    object.h \
    player.h
