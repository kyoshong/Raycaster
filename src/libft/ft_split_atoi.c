/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:07:50 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/30 16:52:43 by hyospark         ###   ########.fr       */
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
		if (i_result[i] > 226 || i_result[i] < 0)
			return (NULL);
		i++;
	}
	return (i_result);
}

int			*ft_split_atoi(char const *s, char c)
{
	int		word_num;
	char	**result;

	if (s == 0)
		return (NULL);
	word_num = word_count(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (word_num + 1))))
		return (NULL);
	if (split2(result, s, c, word_num) == NULL)
	{
		while (word_num >= 0)
			free(result[word_num--]);
		free(result);
	}
	else
		return (ft_split_atoi2(result, word_num));
	return (NULL);
}
