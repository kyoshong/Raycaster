/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:10:14 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:15:35 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = NULL;
	if (*s == '\0' && c == 0)
		return ((char *)s);
	while (*s)
	{
		if (*s == (char)c)
			temp = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (temp);
}
