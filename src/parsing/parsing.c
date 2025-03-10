/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:37:13 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/10 15:53:00 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


void	parsing(char *input, t_shell *shell)
{
	shell->tokens = tokenize(input);
	shell->tokens_copy = shell->tokens;
    shell->root = parse(&shell->tokens);
    if (shell->root)
    	print_ast(shell->root, 0);
    printf("\n");
}