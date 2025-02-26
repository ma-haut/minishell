/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:55:57 by md-harco          #+#    #+#             */
/*   Updated: 2025/02/26 18:06:41 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	check_infile(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		perror_exit(pathname);
	return (fd);
}

int	check_outfile(char *pathname)
{
	int	fd;

	if (access(pathname, F_OK) != 0)
		fd = open(pathname, O_CREAT | O_RDWR, 0644);
	else
		fd = open(pathname, O_RDWR);
	if (fd == -1)
		perror_exit(pathname);
	return (fd);
}

int check_outfile_app(char *pathname)
{
	int	fd;

	if (access(pathname, F_OK) != 0)
		fd = open(pathname, O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(pathname, O_RDWR | O_APPEND);
	if (fd == -1)
		perror_exit(pathname);
	return (fd);
}
