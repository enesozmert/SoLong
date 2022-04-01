#Definition

NAME		=	libft.a
INCLUDES	=	include/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs

#Directory

FTIS		=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM		=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset ft_memcpy

FTPUT		=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO		=	ft_atoi ft_itoa ft_tolower ft_toupper

FTSTR		=	ft_strchr ft_strdup ft_strjoin ft_split \
				ft_strlcat ft_strlcpy ft_strlen ft_strncmp \
				ft_strnstr ft_strrchr ft_strtrim ft_substr \
				ft_strncpy ft_strndup ft_strmapi \
				ft_striteri

FTLST		=	ft_lstnew ft_lstadd_front ft_lstadd_back \
				ft_lstlast ft_lstsize \
				ft_lstdelone ft_lstclear \
				ft_lstiter ft_lstmap

#FileCreate

SRC_FILES+=$(FTIS)
SRC_FILES+=$(FTMEM)
SRC_FILES+=$(FTPUT)
SRC_FILES+=$(FTTO)
SRC_FILES+=$(FTSTR)
BONUS_FILES+=$(FTLST)

SRC 		= 	$(addsuffix .c, $(SRC_FILES))
OBJ 		= 	$(addsuffix .o, $(SRC_FILES))
BONUS_OBJ	= 	$(addsuffix .o, $(BONUS_FILES))

all:			$(NAME)

%.o:%.c 
			@echo Compiling:
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
			@echo Compiling Success file is : $< $(SRC_DIR) $@ 

bonus:		$(BONUS_OBJ)
			@$(AR) $(NAME) $(BONUS_OBJ)
			@echo "Libft bonus compiled!"

norm:
			@norminette $(SRC) $(INCLUDES) | grep -v Norme -B1 || true
			@echo Norminatte exception

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo Libft compiled!

clean:
			@$(RM) -rf $(OBJ) $(BONUS_OBJ)
			@echo Libft objects files cleaned!

fclean:		clean
			@$(RM) -f $(NAME)
			@echo Libft executable files cleaned!

re:			fclean all
			@echo Cleaned and rebuilt

.PHONY:		all clean fclean re bonus norm
