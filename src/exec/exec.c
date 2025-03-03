/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:05:30 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/03 17:46:33 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	handle_files(int fd_in, int fd_out)
{
	if (fd_in != STDIN_FILENO)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	if (fd_out != STDOUT_FILENO)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
}

int	process_child(int i, t_ast *ast, t_shell *shell)
{
	int		fd_in;
	int		fd_out;
	t_ast	*current;
	char	*path;

	current = ast;
	fd_in = identify_infile(i, ast, shell);
	printf("infile = %i\n", fd_in);
	fd_out = identify_outfile(i, ast, shell);
	printf("outfile = %i\n", fd_in);
	handle_files(fd_in, fd_out);
	printf("current->type = %i\n", current->type);
	while (current->type != NODE_COMMAND)
		current = current->right;
	int j = 0;
	while (current->value[j])
		printf("current->value = %s\n", current->value[j++]);
	if (is_builtin(current->value[0]))
		return(execute_builtin(current->value[0], current->value + 1, shell));
	else if (access(current->value[0], X_OK) == 0)
		execve(current->value[0], current->value, shell->envp);
	path = get_path(current->value[0], shell->envp);
	if (path == NULL)
		error_command(current->value[0], shell);
	execve(path, current->value, shell->envp);
	exit(127);
}

int	process_parent(t_shell *shell)
{
	int	i;
	int	status;

	i = 0;
	while (i < shell->nbpipes)
	{
		close(shell->pipes[i][0]);
		close(shell->pipes[i][1]);
		i++;
	}
	i = 0;
	while (i < shell->nbproc - 1)
	{
		wait(NULL);
		i++;
	}
	wait(&status);
	return (status);
}

/* void	case_builtin(t_ast *current, t_ast *cmd_node, t_shell *shell)
{
	int	status;
	int	stdin_backup;
	int	stdout_backup;
	int	fd_in;
	int	fd_out;
	
	stdin_backup = dup(STDIN_FILENO);
	stdout_backup = dup(STDOUT_FILENO);
	fd_in = identify_infile(0, current, shell);
	fd_out = identify_outfile(0, current, shell);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	status = execute_builtin(cmd_node->value, shell);
	dup2(stdin_backup, STDIN_FILENO);
	dup2(stdout_backup, STDOUT_FILENO);
	close(stdin_backup);
	close(stdout_backup);
	close(fd_in);
	close(fd_out);
	return (status);
} */

int	exec_segment(t_ast *current, t_shell *shell)
{
	int		i;
	int		status;
	t_ast	*cmd_node;

	i = 0;
	cmd_node = current;
	while (cmd_node && cmd_node->type != NODE_COMMAND)
		cmd_node = cmd_node->right;	
	while (i < shell->nbproc)
	{
		if (i < shell->nbpipes && pipe(shell->pipes[i++]) != 0)
			perror_exit("pipe");
		if ((shell->pids[i] = fork()) < 0)
			perror_exit("fork");
		if (shell->pids[i] == 0)
			process_child(i, current, shell);
		while (current && current->left->type != NODE_PIPE)
			current = current->right;
		i++;
	}
	status = process_parent(shell);
	while (current && current->type != NODE_OR && current->type != NODE_AND)
		current = current->right;
	return (status);
}

void	exec_line(t_ast *ast, t_shell *shell)
{
	t_ast	*current;
	int		status;

	current = ast;
	while (current)
	{
		get_segment_info(current, shell);
		printf("nombre de pipes = %i\n", shell->nbpipes);
		if (shell->nbpipes == 0)
			status = process_child(0, current, shell);
		else
			status = exec_segment(current, shell);
		if (current->type == NODE_AND && status == 0)
			current = current->right;
		else if (current->type == NODE_OR && status != 0)
			current = current->right;
		else
			current = NULL;
	}
}
