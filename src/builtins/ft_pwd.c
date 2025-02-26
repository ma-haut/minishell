/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:00:37 by md-harco          #+#    #+#             */
/*   Updated: 2025/02/26 13:58:59 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* args = tout ce qui suit la commande pwd et precede la redirection */
/* dans limits.h la longueur max d'un path est 4096 */

void	ft_pwd(char **args)
{
	char	cwd[4096];

	if (args)
	{
		ft_putstr_fd("minishell: pwd: too many arguments\n", 2);
		return ;
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("minishell: pwd");
		return ;
	}
	ft_printf("%s\n", cwd);
}
