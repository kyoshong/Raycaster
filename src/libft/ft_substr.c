/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:10:26 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:15:19 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	j;

	str = (char *)malloc(sizeof(char) * len + 1);
	if (!s || !str)
		return (NULL);
	slen = ft_strlen(s);
	j = 0;
	while (j < len && s[start] != '\0' && start <= slen)
		str[j++] = s[start++];
	str[j] = '\0';
	return (str);
}
