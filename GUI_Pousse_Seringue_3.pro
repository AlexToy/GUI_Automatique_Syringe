QT += widgets
QT += serialport

SOURCES += \
    main.cpp \
    main_windows.cpp \
    slot_seringue.cpp \
    voie1.cpp \
    voie2.cpp \
    voie3.cpp \
    seringue.cpp \
    flechehaut.cpp \
    flechebas.cpp \
    panneau_controle.cpp \
    port_serie.cpp \
    initialisation.cpp \
    nouvelle_seringue.cpp

HEADERS += \
    main_windows.h \
    slot_seringue.h \
    voie1.h \
    voie2.h \
    voie3.h \
    seringue.h \
    flechehaut.h \
    flechebas.h \
    panneau_controle.h \
    port_serie.h \
    initialisation.h \
    nouvelle_seringue.h

RESOURCES += \
    mystylesheet.qrc
