/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:45:19 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:01:42 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cheak_size(long n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	set_negative(long num)
{
	int	s;

	s = 0;
	if (num < 0)
	{
		s = 1;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*n_str;
	int		len;
	int		s;
	long	num;

	num = (long)n;
	s = set_negative(num);
	num = -num;
	len = cheak_size(num);
	n_str = (char *)malloc(sizeof(char) * (len + s + 1));
	if (!n_str)
		return (NULL);
	if (s)
		n_str[0] = '-';
	n_str[len + s] = '\0';
	while (len >= s)
	{
		n_str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (n_str);
}
