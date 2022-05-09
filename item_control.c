/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:18:36 by eozmert           #+#    #+#             */
/*   Updated: 2022/05/09 16:19:00 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_door(t_game *game)
{
	if (game->player.perspective[game->player.direction] != 'E')
		return (1);
	else if (game->player.perspective[3] == 'E')
	{
		player_move_exit(game);
		return (0);
	}
	return (0);
}

int	check_wall(t_game *game)
{
	if (game->player.perspective[game->player.direction] != '1')
		return (1);
	else
		return (0);
}

int	check_total_item(t_game *game)
{
	if (check_wall(game) == 1 && check_door(game) == 1)
		return (1);
	else
		return (0);
	return (0);
}
