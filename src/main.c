/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:34:22 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/03 17:39:43 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	g_last_exit_status;


int main(int ac, char **av, char **envp)
{
    char *input;
    t_token *tokens;
    t_ast *ast;
	t_shell shell;
	(void) ac;
	(void) av;

	initialize_shell(&shell, envp);

    input = "echo 'Hello World'";
    printf("\nTesting: '%s'\n", input);
    tokens = tokenize(input);
    print_tokens(tokens);
    ast = parse(&tokens);
    if (ast) {
        print_ast(ast, 0);
        printf("No errors, AST created successfully.\n");
    } else {
        printf("Error parsing command.\n");
    }
	exec_line(ast, &shell);

    input = "> outfile pwd";
    printf("\nTesting: '%s'\n", input);
    tokens = tokenize(input);
    print_tokens(tokens);
    ast = parse(&tokens);
    if (ast) {
        print_ast(ast, 0);
        printf("No errors, AST created successfully.\n");
    } else {
        printf("Error parsing command.\n");
    }
	exec_line(ast, &shell);

	input = "< infile grep 'hello' | wc -l";
    printf("\nTesting: '%s'\n", input);
    tokens = tokenize(input);
    print_tokens(tokens);
    ast = parse(&tokens);
    if (ast) {
        print_ast(ast, 0);
        printf("No errors, AST created successfully.\n");
    } else {
        printf("Error parsing command.\n");
    }
	exec_line(ast, &shell);

	free_shell(&shell);
}