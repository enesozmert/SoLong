/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42kocaeli.co>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:41:14 by eozmert           #+#    #+#             */
/*   Updated: 2022/02/15 17:08:12 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	count_digits(int value)
{
	int	result;

	result = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= 10;
		result++;
	}
	return (result);
}

static void	put_itoa(char *string, int len, size_t n)
{
	if (n < 10)
		string[len] = n + '0';
	else
	{
		put_itoa(string, len - 1, n / 10);
		string[len] = (n % 10) + '0';
	}
}

char	*ft_itoa(int n)
{
	char		*string;
	size_t		len;
	size_t		num;
	size_t		is_minus;
	long int	n1;

	n1 = n;
	is_minus = 0;
	if (n1 < 0)
	{
		num = -1 * (size_t)n1;
		is_minus = 1;
	}
	else
		num = n1;
	len = count_digits(num);
	string = (char *)malloc(sizeof(char) * (len + is_minus + 1));
	if (!string)
		return (NULL);
	if (is_minus)
		string[0] = '-';
	put_itoa(string + is_minus, len - 1, num);
	string[len + is_minus] = '\0';
	return (string);
}
