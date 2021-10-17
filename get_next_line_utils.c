/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:36:40 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/17 16:44:57 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_realloc(char *result, unsigned int *size)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (*size * 2));
	if (!tmp)
	{
		free(result);
		return ((void *)0);
	}
	while(i < *size)
	{
		tmp[i] = result[i];
		i++;
	}
	*size = *size * 2;
	free(result);
	return (tmp);
}
