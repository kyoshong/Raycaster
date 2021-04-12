/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:14:58 by hyospark          #+#    #+#             */
/*   Updated: 2021/01/13 13:07:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t s)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(*str) * count * s)))
		return (NULL);
	ft_memset(str, 0, count * s);
	return (str);
}
