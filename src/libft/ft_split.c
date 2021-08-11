/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:42:34 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:16:39 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

char	*word_make(char *word, char const *s, int j, int word_len)
{
	int		i;

	i = 0;
	while (word_len)
		word[i++] = s[j - word_len--];
	word[i] = '\0';
	return (word);
}

int	split2(char **result, char const *s, char c, int word_num)
{
	int		i;
	int		j;
	int		word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (s[j] && i < word_num)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			word_len++;
		}
		result[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!result[i])
			return (i);
		word_make(result[i], s, j, word_len);
		word_len = 0;
		i++;
	}
	result[i] = 0;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	int		word_num;
	char	**result;
	int		i;

	if (s == 0)
		return (NULL);
	word_num = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!result)
		return (NULL);
	i = split2(result, s, c, word_num);
	if (i >= 0)
	{
		while (i >= 0)
			free(result[i--]);
		free(result);
	}
	return (result);
}
