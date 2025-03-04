/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:58:06 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/03 17:16:31 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	free_strtab(char **strtab)
{
	int	i;

	i = 0;
	while (strtab[i])
		free(strtab[i++]);
	free(strtab);
}

void	free_shell(t_shell *shell)
{
	free_strtab(shell->envp);
	free(shell->pids);
	free(shell->pipes);
}
