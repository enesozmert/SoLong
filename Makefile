CC          =   gcc
MINILIBX    =   minilibx/libmlx.a
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

FTPRINT		=	main.c

FTSTR		=	rgb_hex.c

#FileCreate

SRC_FILES+=$(FTPRINT)
SRC_FILES+=$(FTSTR)

SRC 		= 	$(addsuffix .c, $(SRC_FILES))
OBJ 		= 	$(addsuffix .o, $(SRC_FILES))

all:			$(NAME)

%.o:%.c 
			@echo Compiling:
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
			@echo Compiling Success file is : $< $(SRC_DIR) $@ 

norm:
			@norminette $(SRC) $(INCLUDES) | grep -v Norme -B1 || true
			@echo Norminatte exception

build:
			@gcc -Wall -Wextra -Werror $(LFLAGS) $(OBJS) *.c
			@echo Build ok

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo Libft compiled!

clean:
			@$(RM) -rf $(OBJ)
			@echo Libft objects files cleaned!

fclean:		clean
			@$(RM) -f $(NAME)
			@echo Libft executable files cleaned!

re:			fclean all
			@echo Cleaned and rebuilt

.PHONY:		all clean fclean re bonus norm














