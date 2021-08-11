/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:10:24 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:15:38 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;

	if (*little == '\0')
		return ((char *)big);
	a = ft_strlen(little);
	while (*big && len-- >= a)
	{
		if (*big == *little && ft_memcmp(big, little, a) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
