/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:24:29 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:12:00 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_l;
	size_t	src_l;

	j = 0;
	while (j < size && dest[j])
		j++;
	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	if (size < dest_l + 1)
		return (size + src_l);
	i = 0;
	while (i < src_l && size > (dest_l + i + 1))
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (j + src_l);
}
