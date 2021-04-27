/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:02:52 by hyospark          #+#    #+#             */
/*   Updated: 2021/04/27 21:56:44 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(int error)
{
	if (error == ARG_ERROR_TOO_FEW)
		printf("ERROR\nARG_ERROR_TOO_FEW");
	else if (error == ARG_ERROR_TOO_MANY)
		printf("ERROR\nARG_ERROR_TOO_MANY");
	else if (error == FILE_NAME_ERROR)
		printf("ERROR\nFILE_NAME_ERROR");
	else if (error == FILE_NAME_ERROR)
		printf("ERROR\nFILE_NAME_ERROR");
	else if (error == SAVE_FLAG_ERROR)
		printf("ERROR\nSAVE_FLAG_ERROR");
}
