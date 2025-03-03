/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:51:39 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/03 17:31:05 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "global.h"
# include "parsing.h"

/* utils */
void	free_strtab(char **strtab);
void	free_shell(t_shell *shell);
void	initialize_shell(t_shell *shell, char **envp);
void	perror_exit(char *msg);

/* env tools */
char	**dup_env(char **env);
int		is_var(char *var, t_shell *shell);
void	update_var(t_shell *shell, char *name, char *value);

/* built-in comands */
int	ft_echo(char **args);
int	ft_cd(char **args, t_shell *shell);
int	ft_pwd(char **args);
int	ft_export(char **args, t_shell *shell);
int	ft_unset(char **args, t_shell *shell);
int	ft_env(char **args, t_shell *shell);
int	ft_exit(char **args, t_shell *shell);

void	exec_line(t_ast *ast, t_shell *shell);
void	get_segment_info(t_ast *ast, t_shell *shell);
char	*get_path(char *cmd, char **envp);
int		is_builtin(char *cmd);
int		execute_builtin(char *cmd, char **args, t_shell *shell);
void	error_command(char *cmd, t_shell *shell);

int		identify_infile(int	i, t_ast *ast, t_shell *shell);
int		identify_outfile(int	i, t_ast *ast, t_shell *shell);

#endif