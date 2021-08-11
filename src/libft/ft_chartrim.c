/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:20:05 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:19:33 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	count_char(char *s1, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	*ft_chartrim(char *s1, char c)
{
	char	*fin;
	size_t	count;
	size_t	i;

	if (!s1 || !c)
		return (NULL);
	count = count_char(s1, c);
	fin = (char *)malloc(sizeof(char) * (ft_strlen(s1) - count + 1));
	if (!fin)
		return (NULL);
	i = 0;
	count = 0;
	while (s1[i])
	{
		if (s1[i] != c)
			fin[count++] = s1[i];
		i++;
	}
	fin[count] = '\0';
	return (fin);
}
