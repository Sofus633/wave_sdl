CC = cc
SRC = main.c user_main.c init_data.c draw_func/draw_face.c matrices/rotations.c vector_2/vec.c
OBJ = $(SRC:.c=.o)
NAME = test_sdl

CFLAGS = -Wall -Wextra -Werror -g -std=gnu99 
LDFLAGS =  -lSDL2 -lGL -lm

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	echo "$< -> $@  ✨"

$(NAME): $(OBJ)
	@echo "\n"
	
	$(CC) $(OBJ) $(LDFLAGS)  -o $(NAME)
	@echo "\n$(OBJ) -> $(NAME) ✨\n"
	@printf "🧙 compilation\033[0;32m SUCESS \033[0m🪄\n"

clean:
	rm -f $(OBJ)
	@printf "🧙 allaways at your service to \033[0;32m CLEAN \033[0m🧹\n"

fclean: clean
	rm -f $(SOURCE)/$(NAME)
	@printf "🧙 Sending everything to the void \033[0;32m FCLEAN \033[0m🌌\n"

re: fclean all