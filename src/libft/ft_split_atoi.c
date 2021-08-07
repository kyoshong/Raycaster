/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:07:50 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/07 23:44:47 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_split_atoi2(char **result, int word_num)
{
	int		*i_result;
	int		i;
	
	if (!(i_result = (int *)malloc(sizeof(int *) * (word_num))))
			return (NULL);
	i = 0;
	while (i < word_num)
	{
		i_result[i] = ft_atoi(result[i]);
		if (i_result[i] > 256 || i_result[i] < 0)
			return (NULL);
		i++;
	}
	i = 0;
	while (i < word_num)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (i_result);
}

int			*ft_split_atoi(char const *s, char c)
{
	int		word_num;
	char	**result;
	int		i;

	if (s == 0)
		return (NULL);
	word_num = word_count(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (word_num + 1))))
		return (NULL);
	i = split2(result, s, c, word_num);
	if (i >= 0)
	{
		while (i >= 0)
			free(result[i--]);
		free(result);
	}
	else
		return (ft_split_atoi2(result, word_num));
	return (NULL);
}
