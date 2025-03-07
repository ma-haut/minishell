/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:58:06 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/07 21:20:25 by md-harco         ###   ########.fr       */
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
	int	i;

	i = 0;
	if (shell->pipe == true)
	{
		free_strtab(shell->envp);
		free_all(shell->root, shell->tokens_copy);
		if (shell->fd_in != STDIN_FILENO)
			close(shell->fd_in);
		if (shell->fd_out != STDOUT_FILENO)
			close(shell->fd_out);
		free(shell->pids);
		while (i < shell->cmd_count - 1)
			free(shell->pipes[i++]);
		free(shell->pipes);
	}
}

void	free_shell_end(t_shell *shell)
{
	int	i;

	i = 0;
	free_strtab(shell->envp);
	free_all(shell->root, shell->tokens_copy);
	if (shell->fd_in != STDIN_FILENO)
		close(shell->fd_in);
	if (shell->fd_out != STDOUT_FILENO)
		close(shell->fd_out);
}
