/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:36:40 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/26 15:55:31 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*my_realloc(char *result, unsigned int *size, int mod)
{
	char			*tmp;

	if (mod)
	{
		tmp = (char *)malloc(sizeof(char) * (*size));
		if (!tmp)
			return ((void *)0);
		tmp[0] = -1;
	}
	else
		tmp = my_realloc_two(result, size);
	return (tmp);
}

char	*my_realloc_two(char *result, unsigned int *size)
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
	while (i < *size)
	{
		tmp[i] = result[i];
		i++;
	}
	*size = *size * 2;
	free(result);
	return (tmp);
}

int	my_read(int fd, char letter[OPEN_MAX][BUFFER_SIZE], unsigned int *i)
{
	*i = 0;
	return (read(fd, (letter[fd]), BUFFER_SIZE));
}
