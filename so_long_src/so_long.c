/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:19:55 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/20 00:22:03 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_extention(char *str)
{
	while (*str != '.' && *str != '\0')
		str++;
	if (ft_strcmp(".ber", str) != 0)
		ft_error_message("File format is not supported\n");
}

void	ft_create_window(t_game *g)
{
	g->ptr_mlx = mlx_init();
	if (g->ptr_mlx == NULL)
		ft_error_message("coudn't create any connexion bet software and disp\n");
	g->ptr_win = mlx_new_window(g->ptr_mlx, g->size * 50,
			g->n_lines * 50, "so_long");
	if (g->ptr_win == NULL)
		ft_error_message("windows coundn't be created on screen\n");
}

void	ft_variabes_initializer(t_game *g)
{
	g->player = 0;
	g->p_x = 0;
	g->p_y = 0;
	g->space = 0;
	g->collect = 0;
	g->exit = 0;
	g->wall = 0;
	g->n_lines = 0;
	g->size = 0;
	g->move = 1;
}

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
		ft_error_message("Number of Arguments is invalid\n");
	ft_check_extention(av[1]);
	ft_variabes_initializer(&g);
	read_map(av[1], &g);
	ft_check_map(g);
	ft_create_window(g);
}
