/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:22:31 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/20 18:58:47 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->str_line);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		print_error("Map not found\n", 0);
	if (!valid_mapname(argv[1]))
		print_error("Map Name incorrect\n", 0);
	game.mlx = mlx_init();
	map_end_nl(argv[1]);
	map_read(argv[1], &game);
	valid_map(&game);
	param_init(&game);
	if (!has_valid_path(&game))
		print_error("Map that cannot be cleared\n", &game);
	game.win = mlx_new_window(game.mlx, game.width * 64,
			game.heigth * 64, "so_long");
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	image_init(&game);
	setting_img_init(&game);
	mlx_loop(game.mlx);
}
