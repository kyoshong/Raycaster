/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:23:33 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:14:27 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_str(char cp, char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == cp)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*fin;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && check_str(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (check_str(s1[end - 1], set) && end > start)
		end--;
	fin = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!fin)
		return (NULL);
	i = 0;
	while (start < end)
		fin[i++] = s1[start++];
	fin[i] = '\0';
	return (fin);
}
