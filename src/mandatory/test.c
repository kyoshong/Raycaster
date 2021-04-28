/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:23:33 by hyospark          #+#    #+#             */
/*   Updated: 2021/04/28 20:17:43 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static int		check_str(char cp, char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == cp)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_chartrim(char *s1, char c)
{
	char	*fin;
	size_t	count;
	size_t	i;

	count = 0;
	if (!s1 || !c)
		return (NULL);
	while (s1[i])
	{
		if (s1[i] == c)
			count++;
		i++;
	}
	if (!(fin = (char*)malloc(ft_strlen(s1) - count + 1)))
		return (NULL);
	i = 0;
	size_t j = 0;
	while (s1[i])
	{
		if (s1[i] != c)
		{
			fin[j] = s1[i];
			j++;
		}
		i++;
	}
	fin[j] = '\0';
	return (fin);
}

int main()
{
	char *s = "255, 24, 11";
	char *tem = ft_chartrim(s, ' '); 
	printf("%s", tem);
	return 0;
}
