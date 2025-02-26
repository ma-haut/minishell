/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:51:39 by md-harco          #+#    #+#             */
/*   Updated: 2025/02/26 18:02:17 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "libft.h"
# include "global.h"
# include "parsing.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <dirent.h>
# include <limits.h>

/* utils */
void	free_strtab(char **strtab);
void	perror_exit(char *msg);

/* env tools */
char	**dup_env(char **env);

/* built-in comands */
void	ft_echo(char **args);
void	ft_cd(char **args);
void	ft_pwd(char **args);
void	ft_export(char **args, t_shell *shell);
void	ft_unset(char **args, t_shell *shell);
void	ft_env(char **args, t_shell *shell);
void	ft_exit(char **args, t_shell *shell);

void	exec_line(t_ast *ast, t_shell *shell);

#endif