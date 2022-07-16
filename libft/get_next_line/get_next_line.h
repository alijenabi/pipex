/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:36:21 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/22 13:09:44 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

typedef struct s_buffer
{
	ssize_t					size;
	ssize_t					search_index;
	char					*ptr;
}				t_buffer;

typedef struct s_buffer_item
{
	int						fd;
	t_buffer				buffer;
	struct s_buffer_item	*next;
}				t_buffer_item;

/**
 * Reads the file descriptor and gives the next line at each call.
 * @param fd[in]  The file descriptor
 * @return A line read from a file descriptor. Of NULL if nothing else is to 
 *         read or if an error occurres.
 * @note Works both reading from a file and from the standard input.
 * @note Returned line includes the terminating \n character, except if the
 *       end of file was reached and does not end with a \n character.
 * @note This has an undefined behavior if the file pointed to by the file
 *       descriptor changed since the last call.
 * @note This has an undefined behavior when reading a binary file.
 */
char		*get_next_line(int fd);

/**
 * Appends the buffer with a new one.
 * @param buffer[in, out]  The buffer to append to.
 * @param new_buffer[in]   The new buffer.
 * @note This will alocate a new buffer of size buffer size plust new buffer 
 *       size and copies them in to new alocated memory.
 * @note The original buffer and new memory will be freed by this function.
 * @return True(1) if successful, false(0) otherwise.
 */
int			gnl_add_back(t_buffer *buffer, t_buffer *new_buffer);

/**
 * Reads the next chunk of file descriptor on each call.
 * @param fd[in]  The file descriptor
 * @returns Read chunk of file descriptor or NULL in case of error.
 * @note the size of the memory depends on the BUFFER_SIZE and SSIZE_MAX.
 */
t_buffer	gnl_read_next(int fd);

/**
 * Removes the buffer up to index and returns the removed part.
 * @param buffer[in, out]  The buffer to remove from.
 * @param index[in]        The index of the last character in buffer.
 * @return The removed string or null if somthing goes wrong.
 * @note The removed string will be one or two char longer than index which will
 *          be set to '\n' and '\0' depending on the buffer value at the index.
 * @note If the index is negative it will return a null.
 * @note If the index is larger than buffer it will free the buffer's ptr.
 * @note The buffer will be realocated.
 * @note The removed string will be alocated seperatly.
 */
char		*gnl_remove(t_buffer *buffer, int index);

/**
 * Searches for the index of the next endl inside the buffer.
 * @param buffer[in, out]  The buffer.
 * @return The index of the endl (i.e., '\n' character).
 * @note The buffer search index will be altered.
 */
int			gnl_search_endl(t_buffer *buffer);

#endif