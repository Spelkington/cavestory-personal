OBJS = game.o graphics.o main.o input.o sprite.o animated_sprite.o
CC = g++
COMPILER_FLAGS = -w -g
LINKER_FLAGS = -Isource/headers -lSDL2 -lSDL2_image
EXEC_NAME = cave_story

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) objs/*.o $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC_NAME)

main.o:
	$(CC) -c $(LINKER_FLAGS) source/src/main.cpp -o objs/main.o

graphics.o:
	$(CC) -c $(LINKER_FLAGS) source/src/graphics.cpp -o objs/graphics.o

game.o:
	$(CC) -c $(LINKER_FLAGS) source/src/game.cpp -o objs/game.o

input.o:
	$(CC) -c $(LINKER_FLAGS) source/src/input.cpp -o objs/input.o

sprite.o:
	$(CC) -c $(LINKER_FLAGS) source/src/sprite.cpp -o objs/sprite.o

animated_sprite.o:
	$(CC) -c $(LINKER_FLAGS) source/src/animated_sprite.cpp -o objs/animated_sprite.o