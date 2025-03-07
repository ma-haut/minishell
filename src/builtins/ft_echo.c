/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:46:44 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/07 16:12:08 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* args = tout ce qui suit la commande builtin echo et precede la redirection */

int	ft_echo(char **args, t_shell *shell)
{
	int		i;
	bool	newline;

	if (!args)
		return (free_shell(shell), EXIT_FAILURE);
	if (ft_strncmp(args[0], "-n", 3) == 0)
	{
		i = 1;
		newline = false;
	}
	else
	{
		i = 0;
		newline = true;
	}
	while (args[i] && args[i + 1])
		ft_printf("%s ", args[i++]);
	if (newline == true)
		ft_printf("%s\n", args[i]);
	else
		ft_printf("%s", args[i]);
	return (free_shell(shell), EXIT_SUCCESS);
}
