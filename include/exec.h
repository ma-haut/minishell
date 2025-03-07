/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:51:39 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/07 21:21:04 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "global.h"
# include "parsing.h"

/* utils */
void	free_strtab(char **strtab);
void	free_shell(t_shell *shell);
void	free_shell_end(t_shell *shell);
void	initialize_shell(t_shell *shell, char **envp);
void	perror_exit(char *msg);

/* env tools */
char	**dup_env(char **env);
int		is_var(char *var, t_shell *shell);
void	update_var(t_shell *shell, char *name, char *value);

/* built-in commands */
int		ft_echo(char **args, t_shell *shell);
int		ft_cd(char **args, t_shell *shell);
int		ft_pwd(char **args, t_shell *shell);
int		ft_export(char **args, t_shell *shell);
int		ft_unset(char **args, t_shell *shell);
int		ft_env(char **args, t_shell *shell);
int		ft_exit(char **args, t_shell *shell);
int		is_builtin(char *cmd);
int		execute_builtin(char *cmd, char **args, t_shell *shell);

/* exec commands */
char	*get_path(char *cmd, char **envp);
void	error_command(char *cmd, t_shell *shell);
int		execute_command(t_ast *ast, t_shell *shell);
int		execute_single_command(t_ast *node, t_shell *shell);
void	dup_files(int fd_in, int fd_out);

/* files utils */
int		check_infile(char *pathname);
int		check_outfile(char *pathname);
int 	check_outfile_app(char *pathname);
void	change_fd_in(t_shell *shell, int fd);
void	change_fd_out(t_shell *shell, int fd);

int		handle_redir_node(t_ast *node, t_shell *shell);
int		execute_pipe(t_ast *node, t_shell *shell);
int		execute_ast(t_ast *node, t_shell *shell);

#endif