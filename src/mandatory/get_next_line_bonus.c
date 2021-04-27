/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:54:03 by hyospark          #+#    #+#             */
/*   Updated: 2021/02/07 21:59:52 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*re_backup(char *cont)
{
	int		len_c;
	int		i;
	int		j;
	char	*temp;

	if (!cont)
		return (NULL);
	i = 0;
	while (cont[i] && cont[i] != '\n')
		i++;
	if (!cont[i])
		return (NULL);
	len_c = ft_strlen(cont);
	if (!(temp = malloc(sizeof(char) * (len_c - i) + 1)))
	{
		free(cont);
		return (NULL);
	}
	i++;
	j = 0;
	while (cont[i])
		temp[j++] = cont[i++];
	temp[j] = '\0';
	free(cont);
	return (temp);
}

int		line_check(char *cont)
{
	int i;

	if (!cont)
		return (0);
	i = 0;
	while (cont[i])
	{
		if (cont[i++] == '\n')
			return (i);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*cont[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		check;
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	check = 1;
	while (!line_check(cont[fd]) && check != 0)
	{
		if ((check = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		buf[check] = '\0';
		temp = ft_strjoin(cont[fd], buf);
		if (cont[fd])
			free(cont[fd]);
		cont[fd] = temp;
	}
	*line = ft_strdup(cont[fd]);
	cont[fd] = re_backup(cont[fd]);
	if (check == 0)
		return (0);
	return (1);
}
