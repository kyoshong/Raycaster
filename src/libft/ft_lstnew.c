/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 22:19:02 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 18:53:18 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_con;

	n_con = (t_list *)malloc(sizeof(*n_con));
	if (!n_con)
		return (NULL);
	n_con->content = content;
	n_con->next = NULL;
	return (n_con);
}
