/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:33:36 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/03 17:24:10 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* args = tout ce qui suit la commande exit et precede la redirection */

static int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

int	ft_exit(char **args, t_shell *shell)
{
	int	status;
	int	temp;

	status = EXIT_SUCCESS;
	if (args[1])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (args[0] && !ft_isnum(args[0]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
	}
	else if (args[0])
	{
		temp = ft_atoi(args[0]);
		if (temp >= 0 && temp <= 255)
			status = temp;
	}
	ft_printf("exit\n");
	free_strtab(shell->envp);
	exit(status);
}
