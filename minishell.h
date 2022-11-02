/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:05:14 by aomman            #+#    #+#             */
/*   Updated: 2022/10/31 20:05:17 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <curses.h>
# include <term.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cmd
{
	char	*cmd_path;
	char	**arg;
	char	**red;
	int		*type;
	char	**limiter;
	int		in;
	int		out;
}				t_cmd;

typedef struct s_var
{
	int		argc;
	int		i;
	int		j;
	int		pid;
	int		*pid2;
	int		in;
	int		out;
	int		fd[2];
	int		fd_cmd[2];
	int		fd_f;
	int		ex_cod;
	int		*type;
	char	*key_env;
	char	**s_env;
	char	*cmd_path;
	char	*oldpwd;
	char	*key_cmd;
	char	*v_path;
	char	**path;
	char	*pwd_path;
	char	*cmd;
	char	*f_path;
	char	**my_red;
	int		status;
	char	**s_cmd;
}	t_var;

typedef struct s_gvar
{
	int		i;
	char	**env;
	int		ex_code;
	int		flag;
	int		check_herdoc;
	int		n_node;
	int		p_fd;
	int		fil;
	int		hld;
	int		sig;
}	t_gvar;

t_gvar	g_var;

/********************PARCING_PART__1********************/
void	parcing_function(void);
t_list	*error_handling(char *line, char **env);
void	pipeline_loop(t_list *pipeline, int *fd, t_list *head);
void	handel_echo(char *line, char **env);
void	*after_split(char *s_line);
int		ft_count(char *token);
char	*handel_many_red(char *token);
void	*check_tokens(char *token, char *value);
void	free_struct(t_list *pipiline);
char	*fill_help(char *line, int *index, int *row);

char	*expand_dollar(char *line);
char	*expand_herdoc(char *line);
char	*expand_exit_value(char *value, int *index);
char	*join_value(char *value, char c, int *index);
char	*get_value(char *value, char *buff);
char	*join_line(char *value, char *line, int *index, int *flag);
char	*expand(char *value, char *line, int *index, int *flag);
char	*get_s_quote(char *value, char *line, int *index);
char	*skip_herdoc_sign(char *value, int *index);
char	*expand_d_quote(char *value, char *line, int *index);
char	*get_buff(char *line, int *index);

int		ft_isspace(char c);
void	free_struct(t_list *pipiline);
char	**replace_pipe(char **s_line);
int		skip_herdoc(char *line, int index);
void	*ft_cpy(char *dest, char *src, int len);
char	*skip_space(char *s);
int		check_red_type(char *line, int index);
int		skip_double_quote(char *line, int index, int *count);
int		skip_single_quote(char *line, int index, int *count);
void	*ft_cpy(char *dest, char *src, int len);
void	raise_err(char err);
int		search_for_char(char *env);
int		check_condition(char c);

/*********************UTILS****************************/
void	error_msg(char *s);
void	display_msg(char *str);
int		is_quote(char c);
int		count_d_pointer(char **ptr);
int		trow_err(int d_quote, int s_quote);
int		ignore_space(char *line, int i);
char	*skip_space(char *s);
char	*add_space(char *s);
int		skip_char_inside_quote(char *line, int i, int flag);
char	*fo_strjoin(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
void	d_free(char **str);
int		ft_count_word(char *line, int index);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
int		skip_word(char *line, int index, int flag);
int		skip_redirecition(char *line, int index);
char	*find_line(char **env, char *key);
void	open_herdoc(t_list *pipeline);
char	find_type_of_red(char *line);
void	allocate_fill_her(char *line, t_cmd *data, int count_her);
void	allocate_fill_arg(char *line, t_cmd *data, int count_arg);
void	allocate_fill_red(char *line, t_cmd *data, int count_red);
char	*fill_d_struct(char *line, int *index, char *str, int *row);
char	*fill_struct(char *line, int *index, char *str, int *row);

/********************CHECK_TOKENS***********************/
int		check_pipe_error(char *line);
int		redirection_error(char **s_line);
int		ft_isspace(char c);
int		is_metachar(char c);

/*******************REDIRECTION*******************/
int		count_redirection(char *line);
int		count_herdoc(char *line);
int		check_cmd(char *line, int flag);
int		count_args(char *line);
t_list	*get_full_cmd(char **s_line, char **env);
char	*find_path(char *cmd, char **envp);

/*********************BUILTINS****************************/

int		ft_isalpha_e_u(char c);
int		check_equal(t_var *var);
int		check_digit(t_var *var);
int		check_builtins(t_var *var);
int		ft_char(char *str, char c);
int		ft_error(t_var *var);
void	ft_putstr_fd(char *str, int fd);
void	ft_cmd(t_var *var);
void	ft_command(t_var *var);
void	ft_pwd(t_var *var);
void	n_exec(t_var *var);
void	ft_unset(t_var *var);
void	add_to_history(t_var *var);
void	ft_cd(t_var *var);
void	ft_echo(t_var *var);
void	ft_env(t_var *var);
void	ft_exit(t_var *var);
void	ft_export(t_var *var);
void	normale_export(t_var *var);
void	ft_normale_export2(t_var *var);

/*********************EXECUTION****************************/

void	execution(t_var *var);
void	ft_open_fd(t_var *var);
t_var	*initialise_var(t_list *pars);
t_var	*full_exec(t_list *pipeline, t_list *head, int *pid2);
void	ft_close(void);
void	signals(void);
void	more_command(t_list *pipeline, t_var *var, int *pid2);
void	execution2(t_var *var, t_list *pipeline);
void	ft_execve(t_var *var);
void	ft_while_pipe(t_list *pipeline, t_list *head);
void	ft_wait(t_var *var, int *pid2);
void	ft_dup(t_var *var, t_list *pipeline);
int		ft_isdir(t_var *var);
void	ft_while(t_list *pipeline, int index, int fd[2]);
int		find_limiter(char *str, int fd[2]);
void	handle(int sig);

/*********************SIGNALS****************************/

void	rl_replace_line(const char *text, int clear_undo);

#endif
