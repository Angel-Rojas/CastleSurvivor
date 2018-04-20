#
# Makefile for asteroids game
#
# Enter one of the following
#
# make
# make all
# make asteroids
# make clean
#
$(info Usage ./main)

CFLAGS = -I ./include
#LFLAGS = -lrt -lX11 -lGLU -lGL -pthread -lm
LFLAGS = -lrt -lX11 -lGL

all: main
Mac: mac

main: main.cpp timers.cpp log.cpp Common.h abdullahA.cpp abdullahA.h angelR.cpp angelR.h christyG.cpp christyG.h nygelA.cpp nygelA.h
	g++ $(CFLAGS) main.cpp log.cpp timers.cpp \
	angelR.cpp christyG.cpp nygelA.cpp	\
	libggfonts.a -Wall $(LFLAGS) -o main

mac: main.cpp timers.cpp log.cpp Common.h abdullahA.cpp abdullahA.h angelR.cpp angelR.h christyG.cpp christyG.h nygelA.cpp nygelA.h
	g++ $(CFLAGS) main.cpp log.cpp timers.cpp \
	angelR.cpp christyG.cpp nygelA.cpp	\
	libggfontsMac.a -Wall -I/usr/X11R6/include \
	-L/usr/X11R6/lib -framework OpenGL -framework Cocoa -lX11 -lm -lGL -omain 

clean:
	rm -f main
	rm -f *.o
