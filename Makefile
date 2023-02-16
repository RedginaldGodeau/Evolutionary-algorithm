CC= gcc
DIR= ./src/
DIROBJ= ./obj/
SRC= $(wildcard $(DIR)*.c)
OBJ = $(patsubst %.c,%.o, $(SRC))
NAME = ./debug/debug.exe
RM= rm $(wildcard $(DIR)*.o)
CFLAGS= -Wall -Werror -Wextra -pedantic 

all: $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)