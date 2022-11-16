/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:19:55 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/16 21:01:47 by rel-hach         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
		ft_error_message("Number of Arguments is invalid\n");
	ft_check_extention(av[1]);
}
