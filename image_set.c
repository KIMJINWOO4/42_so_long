/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:43:12 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/20 14:41:07 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setting_img2(t_game *game, char tmp, int wid, int hei)
{
	if (tmp == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall,
			wid * 64, hei * 64);
	else if (tmp == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.collect,
			wid * 64, hei * 64);
	else if (tmp == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img.character,
			wid * 64, hei * 64);
	else if (tmp == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.escape,
			wid * 64, hei * 64);
	else if (tmp == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.space,
			wid * 64, hei * 64);
	else
		print_error("map have other character\n", game);
}

void	setting_img(t_game *game)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < game->heigth)
	{
		wid = 0;
		while (wid < game->width)
		{
			setting_img2(game, game->str_line[hei * game->width + wid],
				wid, hei);
			wid++;
		}
		hei++;
	}
}

void	setting_img_init(t_game *game)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < game->heigth)
	{
		wid = 0;
		while (wid < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img.space,
				wid * 64, hei * 64);
			setting_img2(game, game->str_line[hei * game->width + wid],
				wid, hei);
			wid++;
		}
		hei++;
	}
}

void	image_init(t_game *game)
{
	game->img.space = mlx_xpm_file_to_image(game->mlx, "./textures/space.xpm",
			&game->img.img_width, &game->img.img_height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&(game->img.img_width), &(game->img.img_height));
	game->img.character = mlx_xpm_file_to_image(game->mlx,
			"./textures/char.xpm",
			&(game->img.img_width), &(game->img.img_height));
	game->img.collect = mlx_xpm_file_to_image(game->mlx,
			"./textures/collect.xpm",
			&(game->img.img_width), &(game->img.img_height));
	game->img.escape = mlx_xpm_file_to_image(game->mlx, "./textures/escape.xpm",
			&(game->img.img_width), &(game->img.img_height));
	return ;
}
