/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:16:23 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/12 15:47:42 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*n_str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	n_str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!n_str)
		return (NULL);
	if (!s1)
	{
		while (s2[j])
			n_str[i++] = s2[j++];
		n_str[i] = '\0';
		return (n_str);
	}
	while (*s1)
		n_str[i++] = *s1++;
	while (*s2)
		n_str[i++] = *s2++;
	n_str[i] = '\0';
	return (n_str);
}

char	*ft_strdup_gnl(char *s)
{
	char	*tem;
	int		i;
	int		len;

	if (!s)
		return ("");
	len = line_check(s);
	if (len == 0)
		return (s);
	tem = malloc(sizeof(char) * len);
	if (!tem)
		return (0);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		tem[i] = s[i];
		i++;
	}
	tem[i] = '\0';
	return (tem);
}

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
