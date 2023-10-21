/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:09:41 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/17 14:22:42 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlcpy_cl(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (*(src + i))
		i++;
	if (!dest)
		return (i);
	while (j + 1 < size && j < i && *(src + j) != '\n')
	{
		*(dest + j) = *(src + j);
		j++;
	}
	if (size > 0)
		*(dest + j) = '\0';
	return (i);
}

char	*ft_strjoin_oneline(char *s1, char *s2)
{
	size_t	sum;
	size_t	i;
	char	*tmp;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (0);
		*(s1) = '\0';
	}
	if (!s2)
		return (free_str(s1, 0));
	i = ft_strlen(s1);
	sum = i + ft_strlen(s2);
	tmp = (char *)malloc(sum + 1);
	if (!tmp)
		return (free_str(s1, 0));
	ft_strlcpy_cl(tmp, s1, sum + 1);
	ft_strlcpy_cl(tmp + i, s2, sum + 1);
	free(s1);
	return (tmp);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (*(s + i))
		i++;
	tmp = (char *)malloc(i + 1);
	if (!tmp)
		return (0);
	i = 0;
	while (*(s + i) && *(s + i) != '\n')
	{
		*(tmp + i) = *(s + i);
		i++;
	}
	*(tmp + i) = '\0';
	return (tmp);
}

int	width_comp(char *line, int width)
{
	if (line)
	{
		if (line[0] == '\n')
			return (0);
		if (line[ft_strlen(line) - 1] == '\n'
			&& (int)ft_strlen(line) - 1 == width)
			return (0);
		if ((int)ft_strlen(line) == width)
			return (0);
		return (1);
	}
	return (0);
}

void	map_read(char *filename, t_game *game)
{
	int		fd;
	int		flag;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_error("Map open fail.\n", 0);
	line = set_wid(fd, game);
	flag = 1;
	while (flag == 1)
	{
		game->heigth++;
		line = get_next_line(fd);
		if (width_comp(line, game->width))
			print_error("Map must be rectangular.\n", game);
		if (line && line[0] != 0)
		{
			game->str_line = ft_strjoin_oneline(game->str_line, line);
			flag = 1;
		}
		else
			flag = 0;
		free(line);
	}
	close(fd);
}
