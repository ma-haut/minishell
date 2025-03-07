/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:59:06 by md-harco          #+#    #+#             */
/*   Updated: 2025/03/07 17:12:59 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**dup_env(char **env)
{
	char	**copy;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (env[count])
		count++;
	copy = malloc(sizeof(char *) * (count + 1));
	while (i < count)
	{
		copy[i] = ft_strdup(env[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	is_var(char *var, t_shell *shell)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	temp = ft_strjoin(var, "=");
	len = ft_strlen(temp);
	while (shell->envp[i])
	{
		if (ft_strncmp(temp, shell->envp[i], len) == 0)
		{
			free(temp);
			return (1);
		}
		i++;
	}
	free(temp);
	return (0);
}

void	update_var(t_shell *shell, char *name, char *value)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strjoin(name, "=");
	while (ft_strncmp(temp, shell->envp[i], ft_strlen(temp)) != 0)
		i++;
	free(shell->envp[i]);
	shell->envp[i] = ft_strjoin(temp, value);
	return (free(temp), free(name), free(value));
}
