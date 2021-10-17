/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:10:42 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/17 17:25:09 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> //fix it
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*my_realloc(char *result, unsigned int *size);
void	end_logic(char *result, int error, int i);

#endif
