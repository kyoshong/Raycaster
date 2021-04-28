/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:42:34 by hyospark          #+#    #+#             */
/*   Updated: 2021/04/27 23:38:17 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		word_count(char const *s, char c)
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

char	**split2(char **result, char const *s, char c, int word_num)
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
		if (!(result[i] = (char *)malloc(sizeof(char) * (word_len + 1))))
			return (NULL);
		word_make(result[i], s, j, word_len);
		word_len = 0;
		i++;
	}
	result[i] = 0;
	return (result);
}

char		**ft_split(char const *s, char c)
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
	return (result);
}
