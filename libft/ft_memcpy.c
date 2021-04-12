/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 03:21:15 by hyospark          #+#    #+#             */
/*   Updated: 2021/01/12 18:08:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	if (dest == NULL && src == NULL)
		return (dest);
	while (n != 0)
	{
		*((char *)dest + n - 1) = *((char *)src + n - 1);
		n--;
	}
	return (dest);
}
