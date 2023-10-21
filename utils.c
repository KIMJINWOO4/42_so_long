/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:13:39 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/19 16:24:24 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_end(char *result)
{
	if (result[ft_strlen(result) - 1] == '\n')
	{
		free(result);
		print_error("New Line End\n", 0);
	}
}

void	link_end_nl(char *result)
{
	file_null_check(result);
	check_end(result);
}

void	map_end_nl(char *filename)
{
	char	*result;
	int		fd;
	int		flag;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_error("Map open fail.\n", 0);
	flag = 1;
	result = 0;
	while (flag == 1)
	{
		line = get_next_line(fd);
		if (line)
		{
			result = ft_strjoin(result, line);
			flag = 1;
		}
		else
			flag = 0;
		free(line);
	}
	link_end_nl(result);
	free(result);
	close(fd);
}

char	*set_wid(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	file_null_check(line);
	game->heigth = 0;
	game->width = ft_strlen(line) - 1;
	game->str_line = ft_strdup(line);
	free(line);
	return (0);
}
