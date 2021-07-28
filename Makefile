O = obj/
I = inc/
S = src/
L = lib/

include sources.mk
OBJ = $(SRC:$S%.c=$O%.o)

CC = gcc
#REMEMBER TO REMOVE -g
CFLAGS = -Wall -Werror -Wextra -g
INCFLAGS = -I$I

RM = rm -f

.PHONY: all clean fclean re


# MAKERS
all: $(NAME)

$O:
	@mkdir -p $@

$(OBJ): | $O

$O%.o: $S%.c | $O
	@printf "Création des objets en cours : $@ ...\n"
	@$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C lib/libft/
	@printf "Compilation ...\n"
	@$(CC) $^ -L./lib/libft -lft -o $@
	@printf "Have fun :-)\n"
	#./tests/tester.sh

# CLEANERS
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

fcleanlibft:
	make fclean -C lib/libft/
fcleanall: fclean fcleanlibft
reall: fcleanall all


