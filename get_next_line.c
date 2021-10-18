/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:05:55 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/18 13:48:13 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int		save_fd;
	static int		tmp_fd;
	static char		letter[BUFFER_SIZE];//fix it
	char			*result;
	static int		error;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	i = 0;
	j = 0;
	size = BUFFER_SIZE;
	result = (char *)malloc(sizeof(char) * size);
	if (!result)
		return ((void *)0);
	if (fd != save_fd)
	{
		tmp_fd = fd;
		error = read(tmp_fd, letter, BUFFER_SIZE);
	}
	while (error && error != -1 && letter[j] != '\n')
	{
		if (i == size)
		{
			result = my_realloc(result, &size);
			if (!result)
				return ((void *)0);
			error = read(tmp_fd, letter, BUFFER_SIZE);
			j = 0;
		}
		result[i] = letter[j];
		j++;
		i++;
	}
	end_logic(result, error, i);
	save_fd = fd;
	return (result);
}

void	end_logic(char *result, int error, int i)
{
	if (error == 0)
		result[i] = '\0';
	else if (error == -1)
	{
		free(result);
		result = ((void *)0);
	}
	else
	{
		result[i] = '\n';
		result[i + 1] = '\0';
	}
}

int	main()
{
	printf("%d\n", BUFFER_SIZE);
}
