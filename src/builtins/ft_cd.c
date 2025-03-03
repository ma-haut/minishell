/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:59:49 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/03 17:23:37 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* args = tout ce qui suit la commande builtin cd et precede la redirection */

static void	go_to_home(char *home)
{
	if (!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return ;
	}
	if (chdir(home) == -1)
	{
		perror("minishell: cd");
		return ;
	}
}

static char	*find_value(char **envp, char *name)
{
	int		i;
	char 	*value;
	char	*temp;

	i = 0;
	temp = ft_strjoin(name, "=");
	while (ft_strncmp(envp[i], temp, ft_strlen(temp)) != 0)
		i++;
	value = ft_strdup (envp[i] + ft_strlen(temp));
	free(temp);
	return (value);
}

int	ft_cd(char **args, t_shell *shell)
{
	char	*home;
	char	cwd[4096];

	if (!args)
		return (EXIT_FAILURE);
	if (!args[0])
	{
		home = getenv("HOME");
		go_to_home(home);
		update_var(shell, ft_strdup("OLDPWD"), find_value(shell->envp, "PWD"));
		update_var(shell, ft_strdup("PWD"), home);
		return (EXIT_SUCCESS);
	}
	if (args[1])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (chdir(args[0]) == -1)
		return (perror("minishell: cd"), EXIT_FAILURE);
	update_var(shell, ft_strdup("OLDPWD"), find_value(shell->envp, "PWD"));
	update_var(shell, ft_strdup("PWD"), getcwd(cwd, sizeof(cwd)));
	return (EXIT_SUCCESS);
}
