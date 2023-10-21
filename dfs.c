/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:59:28 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/20 18:45:43 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dfs(int x, t_game *game, char *map, char find_char)
{
	int	count;

	if (map[x] == '1')
		return (0);
	if (map[x] != 'V')
	{
		count = 0;
		if (map[x] == find_char && find_char == 'E')
		{
			map[x] = 'V';
			return (1);
		}
		else if (map[x] == find_char)
			count++;
		map[x] = 'V';
		count += dfs(x - game->width, game, map, find_char);
		count += dfs(x + game->width, game, map, find_char);
		count += dfs(x - 1, game, map, find_char);
		count += dfs(x + 1, game, map, find_char);
		return (count);
	}
	return (0);
}

int	has_valid_path(t_game *game)
{
	char	*map_temp_c;
	char	*map_temp_e;
	int		c_count;
	int		e_count;

	map_temp_c = ft_strdup(game->str_line);
	map_temp_e = ft_strdup(game->str_line);
	c_count = dfs((game->y * game->width + game->x), game, map_temp_c, 'C');
	e_count = dfs((game->y * game->width + game->x), game, map_temp_e, 'E');
	free(map_temp_c);
	free(map_temp_e);
	if (c_count != game->max_collect)
		return (0);
	if (e_count != 1)
		return (0);
	return (1);
}
