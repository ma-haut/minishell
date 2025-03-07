/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:50:46 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/07 16:55:10 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "parsing.h"

char	*valid_commands[] = {"echo", "ls", "cat", "grep", "pwd", "cd", "touch", "mkdir", "-l", "env", "-n", "wc", NULL};

char	*valid_operator[] = {"<", "<<", ">", ">>", "|", "||", "&&", NULL};