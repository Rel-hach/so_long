/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:19:21 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/20 00:12:44 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_walls(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[0][j] != '1' || g->map[g->n_lines - 1][j] != '1')
				ft_error_message("Your map must be surrounded by walls");
			j++;
		}
		if (g->map[i][0] != '1' || g->map[i][g->size - 1] != '1')
			ft_error_message("Your map must be surrounded by walls");
		i++;
	}
}

void	ft_check_used_characters(t_game *g, char c, int line, int column)
{
	if (c == 'P' || c == 'C' || c == 'E')
	{
		if (c == 'P')
		{
			g->player++;
			g->p_x = line;
			g->p_y = column;
		}
		if (c == 'C')
			g->collect++;
		if (c == 'E')
			g->exit++;
	}
	else if (c == '0' || c == '1')
		return ;
	else
		ft_error_message("Used of forbidden chars");
}

void	ft_numbers_of_elements(t_game *g)
{
	if (g->collect == 0)
		ft_error_message("Your map needs to have at least one collectible");
	else if (g->player == 0)
		ft_error_message("Your map does not have a Player");
	else if (g->player > 1)
		ft_error_message("Your map can only have one single player");
	else if (g->exit == 0)
		ft_error_message("Your map doesn't have an exit");
}

void	ft_check_map_validity(t_game *g)
{
	int		line;
	int		column;
	char	c;

	line = 0;
	while (g->map[line])
	{
		column = 0;
		while (g->map[line][column] != '\0')
		{
			c = g->map[line][column];
			ft_check_used_characters(g, c, line, column);
			column++;
		}
		line++;
	}
	ft_numbers_of_elements(g);
}

void	ft_check_map(t_game *g)
{
	ft_check_walls(g);
	ft_check_map_validity(g);
}
