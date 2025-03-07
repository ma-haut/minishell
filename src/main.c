/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:34:22 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/07 21:29:23 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	g_last_exit_code;

t_ast *create_ast_node(t_ast_type type, char **value) {
    t_ast *node = malloc(sizeof(t_ast));
    node->type = type;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main(int ac, char **av, char **envp)
{
	t_shell shell;
	char *input;
	(void) ac;
	(void) av;

	initialize_shell(&shell, envp);
	while ((input = readline("minishell$ ")))
	{
		ft_printf_error(2, "|%s|\n", input);
		if (input)
		{
			parsing(input, &shell);
			execute_ast(shell.root, &shell);
		}
		add_history(input);
		free(input);
	}
	rl_clear_history();
	free_shell_end(&shell);
}
