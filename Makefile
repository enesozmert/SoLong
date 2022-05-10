CC          =   gcc
MINILIBX    =   minilibx/libmlx.a
LIBFT		=	include/libft/libft.a
LFLAGS      =   -framework OpenGL -framework AppKit -L./minilibx -lmlx
CFLAGS      =   -I./include -I./libft -I./minilibx
NAME        =   so_long
SRC_DIR     =   src
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs
#Definition

#Directory
BONUS_DIR	=	bonus/

#Files

GBONUS		=	anim_bonus load_bonus enemy_move_bonus

MCOMMON		=	load

GCOMMON		= 	rgb_hex game_exit key_move put_image get_next_line player_move \
				map exception_handler block_count fill_background \
				item_control locations map_size map_control \
				player_move_conditions player_perspective ./bonus/print_screen_bonus

#FileCreate

SRC_FILES_B 	 = $(addprefix $(BONUS_DIR), $(GBONUS))
SRC_FILES   	 = $(GCOMMON)
SRC_FILES_M   	 = $(MCOMMON)

SRC 		= 	$(addsuffix .c, $(SRC_FILES_M))
OBJ 		= 	$(addsuffix .o, $(SRC_FILES_M))

SRC_B		= 	$(addsuffix .c, $(SRC_FILES_B))
OBJ_B 		= 	$(addsuffix .o, $(SRC_FILES_B))

SRC_M 		= 	$(addsuffix .c, $(SRC_FILES))
OBJ_M 		= 	$(addsuffix .o, $(SRC_FILES))

all:			$(NAME)

%.o:%.c 
			@echo Compiling:
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo Compiling Success file is : $< $(SRC_FILES) $@ 

norm:
			@norminette $(SRC) | grep -v Norme -B1 || true
			@echo Norminatte exception

build:
			@gcc $(CFLAGS) $(LIBFT) $(LFLAGS) $(LIBFT) $(SRC) $(SRC_M) 
			@echo Build ok

buildbonus:
			@gcc $(CFLAGS) $(LIBFT) $(LFLAGS) $(LIBFT) $(SRC_M) $(SRC_B)
			@echo Build ok

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo SoLong compiled!

clean:
			@$(RM) -rf $(OBJ)
			@echo SoLong objects files cleaned!

fclean:		clean
			@$(RM) -f $(NAME)
			@echo SoLong executable files cleaned!

re:			fclean all
			@echo Cleaned and rebuilt

.PHONY:		all clean fclean re bonus norm














