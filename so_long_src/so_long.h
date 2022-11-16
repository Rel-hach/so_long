/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:18:39 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/16 21:04:14 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define C "pictures/C.xpm"
# define S "pictures/0.xpm"
# define W "pictures/1.xpm"
# define P "pictures/P.xpm"
# define E "pictures/E.xpm"

# define KEYUP_W  13
# define KEYLEFT_A  0
# define KEYRIGHT_D  2
# define KEYDOWN_S  1
# define KEY_ESC 53
# define BUFFER_SIZE 1000

// LIBRARIES :

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_img
{
	void	*wall;
	void	*space;
	void	*collect;
	void	*player;
	void	*exit;
	int		width;
	int		height;
}			t_img;

typedef struct s_game
{
	t_img	img;
	void	*ptr_mlx;
	void	*ptr_win;
	int		player;
	int		p_x;
	int		p_y;
	int		space;
	char	**map;
	int		collect;
	int		exit;
	int		wall;
	int		n_lines;
	int		size;
	int		move;
}			t_game;

// USED FUNCTIONS 1 :

int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(char *s);

// USED FUNCTIONS 2 :

void	ft_check_extention(char *str);

#endif
