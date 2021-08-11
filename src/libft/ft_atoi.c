/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:58:18 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:10:13 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	space_check(char b)
{
	if (b == ' ' || b == '\n' || b == '\r' || b == '\t' || b == '\f')
		return (1);
	else if (b == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	minus;
	long	num;

	minus = 1;
	i = 0;
	num = 0;
	while (space_check(str[i]) == 1 && str[i] != '\0')
		i++;
	if (str[i] == '-')
		minus = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0' && (str[i] <= '9') && str[i] != '\0'))
	{
		num = (num * 10) + ((str[i] - '0'));
		if (num > 2147483647 && minus == 1)
			return (-1);
		if (num > 2147483648 && minus == -1)
			return (0);
		i++;
	}
	return (num * minus);
}
