/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:14:58 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:11:35 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t s)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * count * s);
	if (!str)
		return (NULL);
	ft_memset(str, 0, count * s);
	return (str);
}
