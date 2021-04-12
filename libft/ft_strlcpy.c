/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:14:23 by hyospark          #+#    #+#             */
/*   Updated: 2021/01/16 19:53:04 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	const char	*s;
	size_t		n;

	s = src;
	n = size;
	if (!dest && !src)
		return (0);
	if (n != 0)
	{
		while (--n != 0)
		{
			if ((*dest = *s) == '\0')
				break ;
			dest++;
			s++;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*dest = '\0';
		while (*s)
			s++;
	}
	return (s - src);
}
