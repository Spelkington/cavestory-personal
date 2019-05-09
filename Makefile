OBJS = graphics.o main.o
CC = g++
COMPILER_FLAGS = -w -g
LINKER_FLAGS = -Isource/headers -lSDL2
OUT_NAME = cave_story

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) objs/*.o $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUT_NAME)

main.o:
	$(CC) -c $(LINKER_FLAGS) source/src/main.cpp -o objs/main.o

graphics.o:
	$(CC) -c $(LINKER_FLAGS) -lSDL2 source/src/graphics.cpp -o objs/graphics.o
