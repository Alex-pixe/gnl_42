/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:10:42 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/26 15:55:15 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*my_realloc(char *result, unsigned int *size, int mod);
void	end_logic(char **result, int error, int i);
char	*clear_end(char *result);
char	*create_result(unsigned int i, int error, int tmp,
			char letter[OPEN_MAX][BUFFER_SIZE]);
char	*some_more_functions(unsigned int i, unsigned int size,
			char *result, int error);
char	*my_realloc_two(char *result, unsigned int *size);
int		my_read(int fd, char letter[OPEN_MAX][BUFFER_SIZE], unsigned int *i);

#endif
