/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:34:59 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/19 16:23:42 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	param_init(t_game *game)
{
	char	*str;
	int		i;

	i = 0;
	str = game->str_line;
	while (str[i] != 'P')
		i++;
	game->x = i % game->width;
	game->y = i / game->width;
	i = 0;
	while (str[i] != 'E')
		i++;
	game->escape = i;
	game->count = 0;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_w(game);
	else if (keycode == KEY_S)
		move_s(game);
	else if (keycode == KEY_A)
		move_a(game);
	else if (keycode == KEY_D)
		move_d(game);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
