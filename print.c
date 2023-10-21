/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:03:54 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/17 16:20:36 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	size;

	size = ft_strlen(s);
	write(fd, s, size);
}

static void	ft_recur(int n, int fd)
{
	unsigned char	c;

	if (n == 0)
		return ;
	ft_recur(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned char	digwr;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n > 9)
		ft_recur(n, fd);
	else if (n > 0)
	{
		digwr = (n % 10) + '0';
		write(fd, &digwr, 1);
	}
	else if (!n)
		write(fd, "0", 1);
	else
	{
		n = -(n);
		write(fd, "-", 1);
		ft_recur(n, fd);
	}
}

void	print_error(char *str, t_game *game)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	if (game)
	{
		if (game->str_line)
			free(game->str_line);
	}
	exit(1);
}

void	print_steps(int i)
{
	ft_putnbr_fd(i, 1);
	ft_putstr_fd("\n", 1);
}
