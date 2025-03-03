/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:37:25 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/03 17:26:16 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* args = tout ce qui suit la commande unset et precede la redirection */

static char	**rm_var_from_env(t_shell *shell, char *var, int n)
{
	char	**new_env;
	char	*temp;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	while (shell->envp[count])
		count++;
	new_env = malloc(sizeof(char *) * (count));
	temp = ft_strjoin(var, "=");
	while (shell->envp[i])
	{
		if (ft_strncmp(temp, shell->envp[i], n))
			new_env[j++] = ft_strdup(shell->envp[i]);
		i++;
	}
	new_env[i] = NULL;
	free(temp);
	free(shell->envp);
	return (new_env);
}

int	ft_unset(char **args, t_shell *shell)
{
	int		i;

	i = 0;
	if (!args || !args[0])
		return (EXIT_FAILURE);
	while (args[i])
	{
		if (is_var(args[i], shell))
			shell->envp = rm_var_from_env(shell, args[i],
					ft_strlen(args[i]) + 1);
		i++;
	}
	return (EXIT_SUCCESS);
}

/* int	main(int ac, char **av, char **env)
{
	t_shell shell;
	char *var_exp[3];
	char *var_un[2];
	(void) ac;
	var_exp[0] = ft_strdup(av[1]);
	var_exp[1] = ft_strdup(av[2]);
	var_exp[2] = ft_strdup(av[3]);
	var_un[0] = ft_strdup(av[4]);
	var_un[1] = ft_strdup(av[5]);
	shell.envp = dup_env(env);
	ft_printf("---BEFORE CHANGES---\n");
	ft_env(NULL, &shell);
	ft_export(var_exp, &shell);
	ft_printf("\n\n---AFTER EXPORT---\n");
	ft_env(NULL, &shell);
	ft_unset(var_un, &shell);
	ft_printf("\n\n---AFTER UNSET---\n");
	ft_env(NULL, &shell);
	free(var_exp[0]);
	free(var_exp[1]);
	free(var_exp[2]);
	free(var_un[0]);
	free(var_un[1]);
	free(shell.envp);
	return (0);
} */
