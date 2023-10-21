/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:21:30 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/20 14:38:29 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_image
{
	void	*collect;
	void	*space;
	void	*wall;
	void	*character;
	void	*escape;

	int		img_width;
	int		img_height;
}	t_image;

typedef struct s_game
{
	int		heigth;
	int		width;

	int		x;
	int		y;
	int		escape;

	int		count;
	int		collect;

	int		max_collect;

	void	*mlx;
	void	*win;

	char	*str_line;

	t_image	img;
}	t_game;

typedef struct s_list
{
	char	*line;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

int		key_press(int keycode, t_game *game);
void	param_init(t_game *game);
void	image_init(t_game *game);
void	map_read(char *filename, t_game *game);
void	setting_img(t_game *game);
char	*get_next_line(int fd);
char	*get_next(int fd, char *result);
char	*ft_get_line(char *result);
char	*keep_next_line(char *result);
size_t	ft_strlen(char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*free_str(void *result, t_list **tmp);
char	*set_wid(int fd, t_game *game);

void	valid_map(t_game *game);
int		valid_mapname(char *str);
int		has_valid_path(t_game *game);

void	file_null_check(char *str);
void	print_error(char *str, t_game *game);
void	ft_putstr_fd(char *s, int fd);
void	print_steps(int i);
void	map_end_nl(char *filename);
void	setting_img_init(t_game *game);

void	move_w(t_game *game);
void	move_s(t_game *game);
void	move_a(t_game *game);
void	move_d(t_game *game);
#endif