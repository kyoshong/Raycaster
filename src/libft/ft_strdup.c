/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:15:13 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:11:01 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tem;
	int		i;
	int		len;

	len = ft_strlen(s);
	tem = (char *)malloc(sizeof(char) * (len + 1));
	if (!tem)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		tem[i] = s[i];
		i++;
	}
	tem[i] = '\0';
	return (tem);
}
