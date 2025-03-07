/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:03:16 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/07 21:07:40 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	count_cmds(t_ast *node)
{
	int		i;
	t_ast	*current;

	i = 0;
	current = node;
	while (current && current->type == NODE_PIPE)
	{
		current = current->left;
		i++;
	}
	i++;
	return (i);
}

int	**create_pipes(int	cmd_count)
{
	int		**pipes;
	int		i;

	pipes = malloc(sizeof(int *) * (cmd_count - 1));
	if (!pipes)
		perror_exit("malloc");
	i = 0;
	while (i < cmd_count - 1)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i])
			perror_exit("malloc");
		if (pipe(pipes[i]) == -1)
			perror_exit("pipe");
		i++;
	}
	return (pipes);
}

void	create_child_process(t_ast *cmd_node, t_shell *shell, int i)
{
	int		j;

	j = 0;
	shell->pids[i] = fork();
	if (shell->pids[i] < 0)
		perror_exit("fork");
	if (shell->pids[i] == 0)
	{
		while (j < shell->cmd_count - 1)
		{
			if (j == i - 1 && i != 0)
				change_fd_in(shell, shell->pipes[i - 1][0]);
			else
				close(shell->pipes[j][0]);
			if (j == i && i != shell->cmd_count - 1)
				change_fd_out(shell, shell->pipes[i][1]);
			else
				close(shell->pipes[j][1]);
			j++;
		}
		shell->pipe = true;
		exit(execute_ast(cmd_node, shell));
	}
}

int	parent_process(t_shell *shell)
{
	int	i;
	int	status;

	i = 0;
	while (i < shell->cmd_count - 1)
	{
		close(shell->pipes[i][0]);
		close(shell->pipes[i][1]);
		free(shell->pipes[i++]);
	}
	free(shell->pipes);
	i = 0;
	while (i < shell->cmd_count)
	{
		wait4(shell->pids[i], &status, 0, NULL);
		if (i == shell->cmd_count - 1)
        {
			if (WIFEXITED(status))
				g_last_exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				g_last_exit_code = 128 + WTERMSIG(status);
        }
		i++;
	}
	free(shell->pids);
	return (g_last_exit_code);
}

int	execute_pipe(t_ast *node, t_shell *shell)
{
	t_ast	*cmd_node;
	int		i;

	i = 0;
	shell->cmd_count = count_cmds(node);
	shell->pipes = create_pipes(shell->cmd_count);
	shell->pids = malloc(sizeof(pid_t) * shell->cmd_count);
	if (!shell->pids)
		perror_exit("malloc");
	while (i < shell->cmd_count)
	{
		if (i < shell->cmd_count - 1)
		{
			cmd_node = node->right;
			node = node->left;			
		}
		else
			cmd_node = node;
		create_child_process(cmd_node, shell, i);
		i++;
	}
	return (parent_process(shell));
}
