/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:57:41 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/12 03:40:38 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*ft_strAppend(char *s1, char *s2, char *s3)
{
	char	*n_str;
	int		i;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	if (!s1 && !s2)
		return (NULL);
	n_str = (char *)malloc(len + 1);
	if (!n_str)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		n_str[i++] = *s1++;
	while (*s2 != '\0')
		n_str[i++] = *s2++;
	while (*s3 != '\0')
		n_str[i++] = *s3++;
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
		while (rgb_char[i] != base[j])
			j++;
		rgb += j;
		if (i + 1 < len)
			rgb = rgb * 16;
		i++;
	}
	free(rgb_char);
	return (rgb);
}

int	convert_rgb(int *rgb_int)
{
	int		i;
	char	*rgb;
	char	*rgb2;
	char	*rgb3;
	char	*rgb_list;

	i = 0;
	rgb = ft_get_upper_str(rgb_int[0]);
	rgb2 = ft_get_upper_str(rgb_int[1]);
	rgb3 = ft_get_upper_str(rgb_int[2]);
	rgb_list = ft_strAppend(rgb, rgb2, rgb3);
	free(rgb);
	free(rgb2);
	free(rgb3);
	free(rgb_int);
	return (convert_int(rgb_list));
}
