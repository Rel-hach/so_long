/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:19:59 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/19 01:45:13 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *path_str, t_game *g)
{
	int		fd;
	char	*string;
	char	*temp;

	fd = open(path_str, O_RDONLY, 0777);
	temp = get_next_line(fd);
	if (!temp || temp[0] != '1')
		ft_error_message("Fd doesn't exists, Map is not rectungular or empty");
	g->n_lines = 1;
	while (1)
	{
		string = get_next_line(fd);
		if (!string || string[0] == '\n')
			break ;
		temp = ft_strjoin(temp, string);
		free(string);
		g->n_lines++;
	}
	if (temp[ft_strlen(temp) - 1] == '\n')
		ft_error_message("Map must be rectungular");
	g->map = ft_split(temp, '\n');
	g->size = ft_strlen(g->map[0]);
	free(temp);
	free(string);
}
