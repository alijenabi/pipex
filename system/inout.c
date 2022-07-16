/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inout.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:12:07 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/05 23:52:05 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inout.h"
#include "../log/logger.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

/**
 * @brief It changes the stdin file descriptor with a new one.
 * The file descriptor will be closed on success.
 * 
 * @param fd The new file descriptor.
 * @throw Error if cannot switch the file descriptors.
 */
void	read_from(int fd)
{
	char	*message;
	char	*fd_a;
	int		succ;

	succ = dup2(fd, STDIN_FILENO);
	if (succ == -1)
		log_in(ERROR, "process|read_from(1)",
			"Cannot switch the file fd with stdin.");
	else
	{
		close(fd);
		fd_a = ft_itoa(succ);
		message = ft_strjoin("The stdin file diseptor is changed with ", fd_a);
		log_in(INFO, "process|read_from(1)", message);
		free(message);
		free(fd_a);
	}
}

/**
 * @brief It changes the stdout file descriptor with a new one.
 * The file descriptor will be closed on success.
 * 
 * @param fd The new file descriptor.
 * @throw Error if cannot switch the file descriptors.
 */
void	write_to(int fd)
{
	char	*message;
	char	*fd_a;
	int		succ;

	succ = dup2(fd, STDOUT_FILENO);
	if (succ == -1)
		log_in(ERROR, "process|write_to(1)",
			"Cannot switch the file fd with stdout.");
	else
	{
		close(fd);
		fd_a = ft_itoa(succ);
		message = ft_strjoin("The stdout file diseptor is changed with ", fd_a);
		log_in(INFO, "process|write_to(1)", message);
		free(fd_a);
		free(message);
	}
}

/**
 * @brief Gets the file descriptor of a givn file.
 * 
 * @param file_path The file path.
 * @param source    The reading mode.
 * @return The file descriptor of the oped file.
 * @throw Error if cannot open the file.
 * @throw Error if wrong source is used.
 */
int	file_fd(const char *file_path, enum e_reading_source source)
{
	int	file_fd;

	file_fd = -1;
	if (source == READ_FROM_FILE)
	{
		file_fd = open(file_path, O_RDONLY, 0644);
		if (file_fd == -1)
			log_in(ERROR, "process|file_fd(1)", "Cannot read from the file.");
	}
	else if (source == WRITE_TO_FILE)
	{
		file_fd = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (file_fd == -1)
			log_in(ERROR, "process|file_fd(1)", "Cannot write to the file.");
	}
	else if (source == APPEND_TO_FILE)
	{
		file_fd = open(file_path, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (file_fd == -1)
			log_in(ERROR, "process|file_fd(1)", "Cannot write to the file.");
	}
	else
		log_in(ERROR, "process|file_fd(1)", "Wrong source.");
	return (file_fd);
}
