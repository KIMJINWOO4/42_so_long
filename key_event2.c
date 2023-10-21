/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:34:10 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/19 16:30:48 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'P')
			break ;
	}
	return (i);
}

void	move_w(t_game *game)
{
	int	i;

	i = check_player(game);
	if (game->str_line[i - game->width] == 'C')
		game->collect++;
	if (game->str_line[i - game->width] == 'E'
		&& game->max_collect == game->collect)
	{
		print_steps(game->count + 1);
		ft_putstr_fd("Congratulation\n", 1);
		exit(0);
	}
	else if (game->str_line[i - game->width] != '1')
	{
		if (i == game->escape)
			game->str_line[i] = 'E';
		else
			game->str_line[i] = '0';
		game->str_line[i - game->width] = 'P';
		game->count++;
		print_steps(game->count);
		setting_img(game);
	}
}

void	move_s(t_game *game)
{
	int	i;

	i = check_player(game);
	if (game->str_line[i + game->width] == 'C')
		game->collect++;
	if (game->str_line[i + game->width] == 'E'
		&& game->max_collect == game->collect)
	{
		print_steps(game->count + 1);
		ft_putstr_fd("Congratulation\n", 1);
		exit(0);
	}
	else if (game->str_line[i + game->width] != '1')
	{
		if (i == game->escape)
			game->str_line[i] = 'E';
		else
			game->str_line[i] = '0';
		game->str_line[i + game->width] = 'P';
		game->count++;
		print_steps(game->count);
		setting_img(game);
	}
}

void	move_a(t_game *game)
{
	int	i;

	i = check_player(game);
	if (game->str_line[i - 1] == 'C')
		game->collect++;
	if (game->str_line[i - 1] == 'E'
		&& game->max_collect == game->collect)
	{
		print_steps(game->count + 1);
		ft_putstr_fd("Congratulation\n", 1);
		exit(0);
	}
	else if (game->str_line[i - 1] != '1')
	{
		if (i == game->escape)
			game->str_line[i] = 'E';
		else
			game->str_line[i] = '0';
		game->str_line[i - 1] = 'P';
		game->count++;
		print_steps(game->count);
		setting_img(game);
	}
}

void	move_d(t_game *game)
{
	int	i;

	i = check_player(game);
	if (game->str_line[i + 1] == 'C')
		game->collect++;
	if (game->str_line[i + 1] == 'E'
		&& game->max_collect == game->collect)
	{
		print_steps(game->count + 1);
		ft_putstr_fd("Congratulation\n", 1);
		exit(0);
	}
	else if (game->str_line[i + 1] != '1')
	{
		if (i == game->escape)
			game->str_line[i] = 'E';
		else
			game->str_line[i] = '0';
		game->str_line[i + 1] = 'P';
		game->count++;
		print_steps(game->count);
		setting_img(game);
	}
}
