/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:36:32 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/25 12:38:04 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Gets everything left in the current, removes (i.e., frees) the
 *        current from the list (head) too.
 * 
 * @param current 
 * @param head The head of the buffer list.
 * @param fd   The file descriptor.
 * @return char* 
 */
static char		*st_get_all(t_buffer **current, t_buffer_item **head, int fd);

/**
 * Gets the buffer for the given file descriptor from the buffer list.
 * @param head The head of the buffer list.
 * @param fd   The file descriptor.
 * @return The pointer to the requsted buffer.
 * @note If the buffer does not exist in the list, adds it to the fron of the
 *       list and returns it.
 */
static t_buffer	*st_get_buffer(t_buffer_item **head, int fd);

/**
 * Removes the buffer bellonging to the file desciptor from the buffer list.
 * @param head The head of the buffer list.
 * @param fd   The file descriptor.
 * @return NULL at all time.
 */
static void		*st_remove_buffer(t_buffer_item **head, int fd);

char	*get_next_line(int fd)
{
	static t_buffer_item	*head = NULL;
	t_buffer				*current;
	t_buffer				temp;
	int						endl_index;

	current = st_get_buffer(&head, fd);
	if (!current->ptr)
		*current = gnl_read_next(fd);
	if (!current->ptr)
		return (st_remove_buffer(&head, fd));
	while (1)
	{	
		endl_index = gnl_search_endl(current);
		if (endl_index >= 0)
			return (gnl_remove(current, endl_index));
		else
		{
			temp = gnl_read_next(fd);
			if (!gnl_add_back(current, &temp))
				return (st_get_all(&current, &head, fd));
		}
	}
}

static char	*st_get_all(t_buffer **current, t_buffer_item **head, int fd)
{
	char	*temp;

	temp = gnl_remove(*current, (*current)->size);
	st_remove_buffer(head, fd);
	return (temp);
}

static void	*st_remove_buffer(t_buffer_item **head, int fd)
{
	t_buffer_item	*itr;
	t_buffer_item	*itr_b;

	itr = *head;
	itr_b = NULL;
	while (itr)
	{
		if (itr->fd == fd)
		{
			if (itr_b)
				itr_b->next = itr->next;
			if (itr->buffer.ptr)
				free(itr->buffer.ptr);
			if (!itr_b)
				*head = itr->next;
			free(itr);
			return (NULL);
		}
		itr_b = itr;
		itr = itr->next;
	}
	return (NULL);
}

static t_buffer	*st_get_buffer(t_buffer_item **head, int fd)
{
	t_buffer_item			*itr;

	itr = *head;
	while (itr)
	{
		if (itr->fd == fd)
			return (&itr->buffer);
		itr = itr->next;
	}
	itr = (t_buffer_item *)malloc(sizeof(t_buffer_item));
	itr->next = itr;
	itr->fd = fd;
	itr->buffer.ptr = NULL;
	if (*head)
	{
		itr->next = (*head)->next;
		(*head)->next = itr;
	}
	else
	{
		itr->next = NULL;
		(*head) = itr;
	}
	return (st_get_buffer(head, fd));
}
