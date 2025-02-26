/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:59:49 by md-harco          #+#    #+#             */
/*   Updated: 2025/02/26 14:20:15 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* args = tout ce qui suit la commande builtin cd et precede la redirection */

static void	go_to_home(char *home)
{
	if (!home)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return ;
	}
	if (chdir(home) == -1)
	{
		perror("cd");
		return ;
	}
}

void	ft_cd(char **args)
{
	char	*home;

	if (!args)
		return ;
	if (!args[0])
	{
		home = getenv("HOME");
		go_to_home(home);
		return ;
	}
	if (args[1])
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return ;
	}
	if (chdir(args[0]) == -1)
		perror("cd");
}
