/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:13:48 by hyospark          #+#    #+#             */
/*   Updated: 2021/01/13 12:35:06 by marvin           ###   ########.fr       */
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
		ch = (((unsigned char *)src)[i] == (unsigned char)c) ? 1 : 0;
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
