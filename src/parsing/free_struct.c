/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:53:33 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/07 03:27:07 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void free_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return;
	if (tab[i] == NULL)
		return;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

void free_ast(t_ast *ast)
{
    if (!ast)
        return;
    if (ast->value)
        free_tab(ast->value);
    if (ast->file)
        free(ast->file);
    if (ast->args)
        free_tab(ast->args);
    free_ast(ast->left);
    free_ast(ast->right);
    free(ast);
}


void free_tokens(t_token *tokens)
{
	t_token *tmp;

	while (tokens)
	{
		tmp = tokens->next;
		if (tokens->value)
			free(tokens->value);
		free (tokens);
		tokens = tmp;
	}
}

void free_all(t_ast *ast, t_token *tokens)
{
	free_ast(ast);
	// (void)tokens;
	free_tokens(tokens);
}
