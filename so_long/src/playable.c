/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:51:38 by ferenc            #+#    #+#             */
/*   Updated: 2025/01/20 15:52:00 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

void	check_playable_row(t_win *game, int *c, int *p, int *e)
{
	int	j;
	int	i;

	i = 0;
	while (game->map[i + 1])
	{
		j = 0;
		while (game->map[i][j + 1])
		{
			if (game->map[i][j] == 'C')
				*c = 1;
			if (game->map[i][j] == 'P')
				*p = 1;
			if (game->map[i][j] == 'E')
				*e = 1;
			j++;
		}
		i++;
	}
}

int	check_playable(t_win *game)
{
	int	p;
	int	e;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	check_playable_row(game, &c, &p, &e);
	if (c == 0 || p == 0 || e == 0)
		return (1);
	return (0);
}
