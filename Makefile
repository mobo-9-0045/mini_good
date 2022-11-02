CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror #-g -fsanitize=address

NAME	=	minishell

LIBFT	=	libft/libft.a

SRCS	=	minishell.c\
			minishell_utils.c\
			minishell_utils2.c\
			minishell_utils3.c\
			parsing/parsing.c\
			parsing/error_handling.c\
			parsing/fill_struct/allocate_red.c \
			parsing/fill_struct/allocate_arg.c \
			parsing/fill_struct/allocate_her.c \
			parsing/pipe_check.c \
			parsing/redirection_check.c \
			parsing/expand.c \
			parsing/expand_utils.c \
			parsing/expand_utils1.c \
			parsing/open_herdoc.c \
			parsing/utils.c \
			parsing/utils1.c \
			parsing/tools.c \
			parsing/tools1.c \
			parsing/free.c \
			parsing/display_msg.c \
			parsing/get_full_cmd.c \
			parsing/ft_count_red.c \
			built-ins/built_utils.c\
			built-ins/ft_cd.c\
			built-ins/ft_env.c\
			built-ins/ft_echo.c\
			built-ins/ft_exece_utils.c\
			built-ins/ft_exit.c\
			built-ins/ft_export.c\
			built-ins/ft_normale_export2.c\
			built-ins/ft_pwd.c\
			built-ins/ft_unset.c\
			built-ins/normale_export.c\
			execution/execution.c\
			execution/red.c\
			execution/full_exec.c\
			execution/signals.c\
			execution/more_command.c\


all:	$(NAME)

$(NAME):	$(LIBFT) $(SRCS)
	@ $(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT) -L /Users/aomman/.brew/opt/readline/lib -lreadline -I /Users/aomman/.brew/opt/readline/include
	@ echo "\n\033[1;32mMinishell has been compiled!\033[0m\n"

$(LIBFT):
	@ make -C libft > /dev/null
	@ make bonus -C libft > /dev/null

clean:
	@make clean -C libft

fclean:	clean
	@rm -rf libft/libft.a
	@rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re§