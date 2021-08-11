/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:13:48 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:22:13 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	int		ch;

	i = 0;
	ch = 0;
	while (i < n && ((unsigned char *)src)[i] && !ch)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
			ch = 1;
		else
			ch = 0;
		i++;
	}
	if (ch)
	{
		ft_memcpy(dest, src, i);
		return (dest + i);
		ch--;
	}
	else
	{
		ft_memcpy(dest, src, n);
		return (0);
	}
}
