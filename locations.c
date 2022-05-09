/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:16:18 by eozmert           #+#    #+#             */
/*   Updated: 2022/05/09 16:17:17 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*get_location(t_platform *platform, char block_name)
{
	int	j;
	int	i;
	int	*location;

	i = 0;
	j = 0;
	location = malloc(sizeof(int) * 3);
	while (platform->map[i])
	{
		j = 0;
		while (platform->map[i][j])
		{
			if (platform->map[i][j] == block_name)
			{
				location[0] = i;
				location[1] = j;
			}
			j++;
		}
		i++;
	}
	return (location);
}
