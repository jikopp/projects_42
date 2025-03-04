/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:51:50 by ferenc            #+#    #+#             */
/*   Updated: 2025/01/20 16:40:42 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

int		on_destroy(t_win *game);
int		key_hook(int keycode, t_win *game);
void	update_player_position(t_win *game, int key);
void	count_coins(t_win *game);

int	main(int ac, char **av)
{
	t_win	game;

	if (ac == 2)
	{
		if (save_map(av[1], &game) == 1)
			exit(EXIT_FAILURE);
		count_coins(&game);
		game.mlx_ptr = mlx_init();
		if (!game.mlx_ptr)
			return (1);
		game.win_ptr = mlx_new_window(game.mlx_ptr, (game.map_cols - 1) * 32, \
		(game.map_rows + 1) * 32, "so_long");
		if (!game.win_ptr)
			return (free(game.mlx_ptr), 1);
		open_images(&game);
		add_graphics(&game);
		mlx_key_hook(game.win_ptr, key_hook, &game);
		mlx_hook(game.win_ptr, 17, 0, on_destroy, &game);
		mlx_loop(game.mlx_ptr);
	}
	else
		ft_printf("Error\nOnly one map please, no more or less!\n");
	exit(EXIT_SUCCESS);
}

int	on_destroy(t_win *game)
{
	free_map(game);
	free_player(game);
	free_textures(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_win *game)
{
	if (keycode == 119 || keycode == 115 || keycode == 100 || keycode == 97)
		update_player_position(game, keycode);
	else if (keycode == 65307)
		on_destroy(game);
	return (0);
}

void	update_player_position(t_win *game, int key)
{
	int		i;
	int		j;
	char	*moves;

	i = game->x;
	j = game->y;
	moves = ft_itoa(game->moves);
	ft_printf("%s\n", moves);
	free(moves);
	if (key == 115 && game->map[j + 1][i] != '1')
		move_top(game, i, j);
	else if (key == 119 && game->map[j - 1][i] != '1')
		move_down(game, i, j);
	else if (key == 97 && game->map[j][i - 1] != '1')
		move_left(game, i, j);
	else if (key == 100 && game->map[j][i + 1] != '1')
		move_right(game, i, j);
	if (game->map[game->y][game->x] == 'C')
	{
		game->coins -= 1;
		game->map[game->y][game->x] = '0';
	}
	if (game->map[game->y][game->x] == 'E')
		if (game->coins == 0)
			on_destroy(game);
}

void	count_coins(t_win *game)
{
	int	i;
	int	j;

	game->coins = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->coins += 1;
			j++;
		}
		i++;
	}
}
