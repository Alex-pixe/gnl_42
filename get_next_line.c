/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:11:05 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/19 12:30:05by cbridget         ###   ########.fr       */
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
	static unsigned int	j;
	unsigned int	size;

	i = 0;
	size = BUFFER_SIZE;
	if (fd != save_fd || !fd || j == BUFFER_SIZE)
	{
		if (fd != save_fd)
			tmp_fd = fd;
		error = read(tmp_fd, letter, BUFFER_SIZE);
		j = 0;
	}
	//if (BUFFER_SIZE == 1 && j > 0)
	//{
	//	error = read(tmp_fd, letter, BUFFER_SIZE);
	//	j = 0;
	//}
	result = (char *)malloc(sizeof(char) * size);
	if (!result)
		return ((void *)0);
	result[0] = '\0';
	while (error && error != -1 && (i == 0 || (result[i - 1] && result[i - 1] != '\n')))
	{
		if (i == size)
		{
			result = my_realloc(result, &size);
			if (!result)
				return ((void *)0);
		}
		//if (error || letter[0] != '\n')
		result[i] = letter[j];
		j++;
		if (j == BUFFER_SIZE && result[i] != '\n' && result[i])
		{
			error = read(tmp_fd, letter, BUFFER_SIZE);
			j = 0;
		}
		//printf("j=%d, %s, %d\n", j, letter, error);
		//if (error || letter[0] != '\n')
		//	result[i] = letter[j];
		//j++;
		i++;
	}
	printf("error=%d\n", error);
	end_logic(&result, error, i);
	save_fd = fd;
	return (result);
}

void	end_logic(char **result, int error, int i)
{
	if (!(*result)[0] || error == -1)
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

int	main()
{
	int fd;
	char test[100];
	fd = open("43_no_nl", O_RDONLY);
	//int i = 0;
	int error;
	error = read(fd, test, 10);
	printf("%d", error);
	/*while (i < 3)
	{
		test = get_next_line(fd);
		printf("%s", test);
		//printf("  i=%d\n", i);
		i++;
	}*/
	//test = get_next_line(fd);
	//printf("%s", test);
	//if (test == NULL)
	//	printf("yes");
}
