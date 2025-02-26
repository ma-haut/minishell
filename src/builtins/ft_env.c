/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:33:28 by md-harco          #+#    #+#             */
/*   Updated: 2025/02/26 11:39:54 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* args = tout ce qui suit la commande env et precede la redirection */

void	ft_env(char **args, t_shell *shell)
{
	int	i;

	i = 0;
	if (args)
	{
		ft_putstr_fd("env: too many arguments\n", 2);
		return ;
	}
	while (shell->envp[i])
		ft_printf("%s\n", shell->envp[i++]);
}
