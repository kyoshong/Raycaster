/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:57:41 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/30 22:44:03 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strrev(const char *s)
{
	char	*str;
	size_t	slen;
	size_t	j;
	size_t	len;

	len = ft_strlen(s);
	slen = len;
	if (len == 0)
		return ("");
	if (!s || !(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	j = 0;
	len--;
	while (j < slen)
		str[j++] = s[len--];
	str[j] = '\0';
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
	if (!(str = malloc(sizeof(char) * (len + 2))))
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
	str = ft_strrev(str);
	return (str);
}

int		ft_count_base(int n, int i)
{
	if (n > 16)
		i = ft_count_base(n / 16, i);
	i++;
	return (i);
}

int		ft_get_base_count(int n)
{
	int	i;

	i = ft_count_base(n, 0);
	return (i);
}

char	*ft_strAppend(char *s1, char *s2)
{
	char	*n_str;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!(n_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		n_str[i++] = *s1++;
	while (*s2 != '\0')
		n_str[i++] = *s2++;
	n_str[i] = '\0';
	return (n_str);
}

int	convert_int(char *rgb_char)
{
	int		i;
	int		len;
	int		rgb;
	char	*base;
	int		j;
	
	i = 0;
	len = ft_strlen(rgb_char);
	base = "0123456789ABCDEF";
	rgb = 0;
	while (i < len)
	{
		j = 0;
		while(rgb_char[i] != base[j])
			j++;
		rgb += j;
		if (i + 1 < len)
			rgb = rgb * 16;
		i++;
	}
	return (rgb);
}

int		convert_rgb(int *rgb_int)
{
	int i;
	char *rgb;
	char *rgb_list;

	i = 0;
	while(i < 3)
	{
		rgb_list = ft_get_upper_str(rgb_int[i]);
		if (ft_strlen(rgb_list) == 1)
			rgb_list = ft_strAppend("0", rgb_list);
		if (i == 0)
			rgb = rgb_list;
		else
			rgb = ft_strAppend(rgb, rgb_list);
		i++;
	}
	return (convert_int(rgb));
}
