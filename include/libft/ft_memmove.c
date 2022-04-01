/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42kocaeli.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:39 by eozmert           #+#    #+#             */
/*   Updated: 2022/02/15 11:38:36 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == src)
		return (dst);
	if (src < dst)
	{
		d = (unsigned char *)dst;
		s = (unsigned char *)src;
		while (n--)
			d[n] = s[n];
	}
	if (src > dst)
		dst = ft_memcpy(dst, src, n);
	return (dst);
}
