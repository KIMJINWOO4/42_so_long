/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:32:36 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/17 16:05:17 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	around_wall(t_game *game)
{
	int		i;
	char	*str;

	str = game->str_line;
	i = -1;
	while (++i < game->width)
	{
		if (str[i] != '1')
			return (0);
	}
	i = 1;
	while (i < game->heigth - 1)
	{
		if (str[i * game->width] != '1'
			|| str[(i + 1) * game->width - 1] != '1')
			return (0);
		i++;
	}
	i = i * game->width - 1;
	while (str[++i])
	{
		if (str[i] != '1')
			return (0);
	}
	return (1);
}

int	least_object(t_game *game)
{
	int		i;
	int		least[2];
	char	*str;

	str = game->str_line;
	least[0] = 0;
	least[1] = 0;
	game->max_collect = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == 'P')
			least[0]++;
		if (str[i] == 'E')
			least[1]++;
		if (str[i] == 'C')
			game->max_collect++;
	}
	if (least[0] != 1 || least[1] != 1 || game->max_collect < 1)
		return (0);
	return (1);
}

int	valid_mapname(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i <= 3)
		return (0);
	i -= 4;
	if (str[i] != '.' || str[i + 1] != 'b'
		|| str[i + 2] != 'e' || str[i + 3] != 'r')
		return (0);
	return (1);
}

void	valid_map(t_game *game)
{
	if (!around_wall(game))
		print_error("Map must be closed/surrounded by wall\n", game);
	if (!least_object(game))
		print_error("map must have 1player, 1exit, 1~collect\n", game);
	if (game->width > 40 || game->heigth > 21)
		print_error("map size is over the monitor size\n", game);
}

void	file_null_check(char *str)
{
	if (str == NULL)
		print_error("EMPTY FILE\n", 0);
}
