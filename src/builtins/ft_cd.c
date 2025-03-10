/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:59:49 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/10 19:07:18 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	go_to_home(t_shell *shell)
{
	char	*home;

	home = ft_getenv(shell, "HOME");
	if (!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (0);
	}
	if (chdir(home) == -1)
	{
		perror("minishell: cd");
		return (free(home), 0);
	}
	return (free(home), 1);
}

int	ft_cd(char **args, t_shell *shell)
{
	char	cwd[4096];
	char	*path;

	path = NULL;
	if (args[2])
		return (ft_putstr_fd("minishell: cd: too many arguments\n", 2),
				EXIT_FAILURE);
	if (!args[1] && !go_to_home(shell))
			return (EXIT_FAILURE);
	else if (ft_strcmp(args[1], "-") == 0)
	{
		if (!(path = ft_getenv(shell, "OLDPWD")))
			return (ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2),
					EXIT_FAILURE);
	}
	else
		path = ft_strdup(args[1]);
	if (path && chdir(path) == -1)
		return (free(path), perror("minishell: cd"), EXIT_FAILURE);
	update_var(shell, "OLDPWD", ft_getenv(shell, "PWD"));
	update_var(shell, "PWD", getcwd(cwd, sizeof(cwd)));
	if (path)
		free(path);
	return (EXIT_SUCCESS);
}
