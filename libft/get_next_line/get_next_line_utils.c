/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:36:41 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/26 12:59:01 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

/**
 * Moves the size chank of the src to dist and moves the rest of the src 
 * forward by size.
 * @param[in, out] dist	The destination string.
 * @param[in, out] src  The source string.
 * @param[in] size      The target size of the dist.
 * @param[in] src_size  Current size of the src.
 * @return The size of the src after the move.
 */
static int	st_move(char **dist, char **src, int size, int src_size);

t_buffer	gnl_read_next(int fd)
{
	t_buffer	buffer;

	buffer.size = 0;
	buffer.search_index = 0;
	buffer.ptr = NULL;
	if (BUFFER_SIZE < 0)
		return (buffer);
	buffer.ptr = (char *)malloc(BUFFER_SIZE);
	if (!buffer.ptr)
		return (buffer);
	buffer.size = read(fd, buffer.ptr, BUFFER_SIZE);
	if (buffer.size <= 0)
	{
		free(buffer.ptr);
		buffer.ptr = 0;
	}
	return (buffer);
}

int	gnl_add_back(t_buffer *buffer, t_buffer *new_buffer)
{
	char	*buf;
	int		itr;

	if (!new_buffer->ptr)
		return (0);
	buf = (char *)malloc((buffer->size + new_buffer->size + 1) * sizeof(char));
	itr = 0;
	while (itr < buffer->size)
	{
		buf[itr] = (*buffer).ptr[itr];
		itr++;
	}
	while (itr < buffer->size + new_buffer->size)
	{
		buf[itr] = (new_buffer->ptr)[itr - buffer->size];
		itr++;
	}
	buf[itr] = '\0';
	free(buffer->ptr);
	buffer->ptr = buf;
	buffer->size += new_buffer->size;
	free(new_buffer->ptr);
	new_buffer->ptr = NULL;
	return (1);
}

char	*gnl_remove(t_buffer *buffer, int index)
{
	char	*ans;
	int		size;

	if (index < 0)
		return (NULL);
	size = index + 1;
	if (index < buffer->size && buffer->ptr[index] == '\n')
		size++;
	if (index > buffer->size)
		size = buffer->size + 1;
	ans = (char *)malloc(size * sizeof(char));
	if (!ans)
		return (NULL);
	buffer->size = st_move(&ans, &(buffer->ptr), size - 1, buffer->size);
	buffer->search_index = 0;
	if (buffer->size == 0)
	{
		free(buffer->ptr);
		buffer->ptr = NULL;
	}
	return ((char *)ans);
}

int	gnl_search_endl(t_buffer *buffer)
{
	int				endl_index;

	endl_index = -1;
	while (buffer->search_index < buffer->size)
	{
		if (*(buffer->ptr + buffer->search_index) == '\n')
		{
			endl_index = buffer->search_index;
			break ;
		}
		buffer->search_index++;
	}
	return (endl_index);
}

static int	st_move(char **dist, char **src, int size, int src_size)
{
	int	itr;
	int	ans;

	itr = 0;
	while (itr < size)
	{
		(*dist)[itr] = (*src)[itr];
		itr++;
	}
	(*dist)[itr] = '\0';
	itr = 0;
	while (itr + size < src_size)
	{
		(*src)[itr] = (*src)[itr + size];
		itr++;
	}
	ans = itr;
	while (itr < src_size)
	{
		(*src)[itr] = '\0';
		itr++;
	}
	return (ans);
}
