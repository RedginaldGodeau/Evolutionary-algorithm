CC= gcc
DIR= ./src/
DIROBJ= ./obj/
SRC= $(wildcard $(DIR)*.c)
OBJ = $(patsubst %.c,%.o, $(SRC))
NAME = ./debug/debug.exe
RM= rm -f
CFLAGS= -Wall -Werror -Wextra -pedantic 

all: $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(DIR)*\~	
oclean:
	$(RM) $(OBJ)
fclean:
	$(RM) $(OBJ) *~ $(NAME)
re:
	$(CC) $(CFLAGS) -o $@ $(OBJ)