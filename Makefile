PROJ_INCS=-I source/headers -L source/objs -lSDL2

PROJ_SRC=source/src
PROJ_OBJS=objs

all: graphics.o
	g++ -g $(PROJ_INCS)    $(PROJ_SRC)/main.cpp -o cave_story

graphics.o:
	g++ -g $(PROJ_INCS) -c $(PROJ_SRC)/graphics.cpp -o $(PROJ_OBJS)/graphics.o
