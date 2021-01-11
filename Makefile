NAME	= libftprintf.a

SRCDIR	= ./
OBJDIR	= ./
SRC		= ${SRCDIR}ft_output.c\
		${SRCDIR}ft_print_number.c\
		${SRCDIR}ft_printf_pointer.c\
		${SRCDIR}ft_printf.c\
		${SRCDIR}output_flag.c\
		${SRCDIR}widht_and_accuracy.c\
		${SRCDIR}check_num.c\
		${SRCDIR}ft_lib_function.c\
		${SRCDIR}ft_output.c\
		${SRCDIR}ft_parser_printf.c\
		${SRCDIR}output.c\
		${SRCDIR}ft_null_pointer.c\
	
	
			


OBJ		= ${patsubst ${SRCDIR}%.c, ${OBJDIR}%.o, ${SRC}}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

${OBJDIR}%.o: ${SRCDIR}%.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJ}
	ar rc $(NAME) ${OBJ}
	ranlib ${NAME}

all:  $(NAME)

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf $(NAME)

re: fclean all
