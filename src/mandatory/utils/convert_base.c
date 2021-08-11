/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:27:14 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 16:01:44 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strrev(char *s)
{
	char	*str;
	size_t	slen;
	size_t	j;
	size_t	len;

	len = ft_strlen(s);
	slen = len;
	if (len == 0)
		return ("");
	if (len == 1)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!s || !str)
		return (NULL);
	j = 0;
	if (len == 1)
		str[j++] = '0';
	len--;
	while (j < slen)
		str[j++] = s[len--];
	str[j] = '\0';
	free(s);
	return (str);
}

char	*ft_get_upper_str(int n)
{
	char	*str;
	char	*base;
	int		i;
	int		len;

	i = 0;
	len = ft_get_base_count(n);
	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	base = "0123456789ABCDEF";
	while (n >= 16)
	{
		str[i] = base[n % 16];
		n /= 16;
		i++;
	}
	str[i++] = base[n];
	str[i] = '\0';
	return (ft_strrev(str));
}

int	ft_count_base(int n, int i)
{
	if (n > 16)
		i = ft_count_base(n / 16, i);
	i++;
	return (i);
}

int	ft_get_base_count(int n)
{
	int	i;

	i = ft_count_base(n, 0);
	return (i);
}
