# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jdel-ros <jdel-ros@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/29 13:54:37 by jdel-ros     #+#   ##    ##    #+#        #
#    Updated: 2020/01/24 14:10:23 by jdel-ros    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

HEADER			=		includes/

LIB				=		libft.a

LIBS			=		libft/libft.a

SRC_PATH		=		sources

SRCS_NAME		=		ft_printf.c ft_type.c ft_initvar.c \
						ft_width.c ft_precision.c ft_flags.c ft_txt.c \
						ft_execwidth.c ft_intlen.c ft_execprec.c \
						ft_exec_s.c ft_execpointer.c ft_execchar.c \
						ft_execpourc.c ft_rectype.c ft_execint.c \
						ft_exec_u_x.c ft_exectype.c ft_execintun.c \
						ft_atoi_printf.c ft_width_prec_neg.c \
						ft_rectypourc.c ft_execintneg.c ft_chrprec.c ft_intchr.c \
						
OBJS			=		${SRCS:.c=.o}

NAME			=		libftprintf.a

RM				=		rm -f

CC				=		gcc

FLAGS			=		-Wall -Wextra -Werror -g3

SRCS			=		$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

# **************************************************************************** #
#                                REGLES                                        #
# **************************************************************************** #

all:                            $(LIB) PRINTF $(NAME)

%.o: %.c                         $(HEADER) $(LIBS)
	@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
	@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

$(NAME):                        $(OBJS) $(HEADER)
	@cp libft/libft.a ./$(NAME)
	@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling Printf\033[0m"
	@ar rcs $(NAME) $(OBJS)

$(LIB):
	@$(MAKE) -C libft all

clean:
	@$(MAKE) -C libft clean
	@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing File object\033[0m"
	@$(RM) $(OBJS)

fclean:                            clean
	@$(MAKE) -C libft fclean
	@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing All\033[0m"
	@$(RM) $(NAME)


test            :all
	@echo "_____________________________________________"
	@$(CC) $(FLAGS) $(NAME) -g sources/main.c && ./a.out
	@echo "\n_____________________________________________"
	@make fclean
	@rm a.out
	@rm -rf a.out.dSYM

vtest            :all
	@echo "_____________________________________________"
	@$(CC) $(FLAGS) $(NAME) -g sources/main.c && valgrind ./a.out
	@echo "\n_____________________________________________"
	@make fclean
	@rm a.out
	@rm -rf a.out.dSYM

re:                                fclean all

PRINTF:
	@echo "__, ___      __, __, _ _, _ ___ __,"
	@echo "|_   |       |_) |_) | |\ |  |  |_ "
	@echo "|    |       |   | \ | | \|  |  |  "
	@echo "~    ~  ~~~~ ~   ~ ~ ~ ~  ~  ~  ~  "
	@echo ""
.PHONY:                         clean fclean
