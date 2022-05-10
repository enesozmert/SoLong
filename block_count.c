/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:51:20 by eozmert           #+#    #+#             */
/*   Updated: 2022/05/10 11:51:41 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_block_count(t_platform *platform, char block_name)
{
	int	j;
	int	i;
	int	result;

	i = 0;
	j = 0;
	result = 0;
	while (platform->map[i])
	{
		j = 0;
		while (platform->map[i][j])
		{
			if (platform->map[i][j] == block_name)
				result++;
			j++;
		}
		i++;
	}
	return (result);
}
