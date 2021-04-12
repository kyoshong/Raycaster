/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:15:13 by hyospark          #+#    #+#             */
/*   Updated: 2021/01/19 15:19:46 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tem;
	int		i;
	int		len;

	len = ft_strlen(s);
	if (!(tem = (char *)malloc((sizeof(char) * len) + 1)))
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
