/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42kocaeli.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:57:37 by eozmert           #+#    #+#             */
/*   Updated: 2022/02/07 12:26:18 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int	index;
	int	length;
	int	empty;

	index = 0;
	empty = 0;
	length = ft_strlen(str) - 1;
	while (index < length)
	{
		empty = str[length];
		str[length] = str[index];
		str[index] = empty;
		index++;
		length--;
	}
	return (str);
}
