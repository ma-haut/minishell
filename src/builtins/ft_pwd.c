/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:00:37 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/07 16:10:12 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* args = tout ce qui suit la commande pwd et precede la redirection */
/* dans limits.h la longueur max d'un path est 4096 */

int	ft_pwd(char **args, t_shell *shell)
{
	char	cwd[4096];

	if (args[0])
	{
		ft_putstr_fd("minishell: pwd: too many arguments\n", 2);
		return (free_shell(shell), EXIT_FAILURE);
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("minishell: pwd");
		return (free_shell(shell), EXIT_FAILURE);
	}
	ft_printf("%s\n", cwd);
	return (free_shell(shell), EXIT_SUCCESS);
}
