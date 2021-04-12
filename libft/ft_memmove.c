/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:14:05 by hyospark          #+#    #+#             */
/*   Updated: 2021/01/19 19:00:40 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		d = (unsigned char *)dest;
		s = (unsigned char *)src;
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d = (unsigned char *)dest + (n - 1);
		s = (unsigned char *)src + (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
