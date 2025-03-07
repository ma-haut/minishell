/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:33:28 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/07 16:08:30 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* args = tout ce qui suit la commande env et precede la redirection */

int	ft_env(char **args, t_shell *shell)
{
	int	i;

	i = 0;
	if (args[0])
	{
		ft_putstr_fd("minishell: env: too many arguments\n", 2);
		return (free_shell(shell), EXIT_FAILURE);
	}
	while (shell->envp[i])
		ft_printf("%s\n", shell->envp[i++]);
	return (free_shell(shell), EXIT_SUCCESS);
}
