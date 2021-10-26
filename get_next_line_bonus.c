/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:40:24 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/26 15:42:16 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char			letter[FOPEN_MAX][BUFFER_SIZE];
	unsigned int		i;
	int					mod;
	int					error;

	mod = 1;
	error = -555;
	i = 0;
	if (fd < 0 || fd > FOPEN_MAX)
		return ((void *)0);
	while (i < BUFFER_SIZE)
	{
		if (letter[fd][i] != 0)
		{
			mod = 0;
			break ;
		}
		i++;
	}
	if (mod)
	{
		error = read(fd, (letter[fd]), BUFFER_SIZE);
		i = 0;
	}
	return (create_result(i, error, fd, letter));
}

char	*create_result(unsigned int i, int error,
			int fd, char letter[FOPEN_MAX][BUFFER_SIZE])
{
	char			*result;
	unsigned int	size;
	unsigned int	j;

	j = 0;
	size = BUFFER_SIZE;
	result = my_realloc((void *)0, &size, 1);
	if (!result)
		return ((void *)0);
	while (error && error != -1 && (j == 0
			|| (result[j - 1] && result[j - 1] != '\n')))
	{
		if (j == size)
			result = my_realloc(result, &size, 0);
		if (!result)
			return ((void *)0);
		result[j++] = letter[fd][i];
		letter[fd][i++] = 0;
		if ((i == BUFFER_SIZE || i == (unsigned int)error)
			&& result[j - 1] != '\n' && result[j - 1])
			error = my_read(fd, letter, &i);
	}
	return (some_more_functions(j, size, result, error));
}

char	*some_more_functions(unsigned int i, unsigned int size,
							char *result, int error)
{
	if (i == size)
		result = my_realloc(result, &size, 0);
	if (!result)
		return ((void *)0);
	end_logic(&result, error, i);
	if (result)
		result = clear_end(result);
	return (result);
}

char	*clear_end(char *result)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (result[i])
		i ++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
	{
		free(result);
		return ((void *)0);
	}
	i = 0;
	while (result[i])
	{
		tmp[i] = result[i];
		i++;
	}
	tmp[i] = '\0';
	free(result);
	return (tmp);
}

void	end_logic(char **result, int error, int i)
{
	if ((*result)[0] == -1 || error == -1)
	{
		free(*result);
		*result = (void *)0;
	}
	else if (!error)
		(*result)[i] = '\0';
	else
	{
		if ((*result)[i - 1] != '\n')
		{
			(*result)[i] = '\n';
			i++;
		}
		(*result)[i] = '\0';
	}
}
