/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:44:17 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/05 22:05:44 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Logs the logging level.
 * 
 * @param level[in]   The message log level.
 * @param fd[in]      The file descriptor to log to.
 * @return The number of characters that are logged.
 */
static int	s_log_level(enum e_log_level level, int fd);

/**
 * @brief Logs the owner of the logging message.
 * 
 * @param fd[in]      The file descriptor to log to.
 * @param owner[in]   The owner of the message.
 * @return The number of characters that are logged.
 */
static int	s_log_owner(int fd, char *owner);

/**
 * @brief Logs the message.
 * 
 * @param fd[in]      The file descriptor to log to.
 * @param owner[in]   The owner of the message.
 * @param message[in] The message to be loged.
 * @return The number of characters that are logged.
 */
static int	s_log_message(int fd, char *owner, char *message);

/**
 * @brief Loges the message.
 * 
 * @note This will only log a message if the message log level is higher than
 * 		 current log level.
 * @param level[in]   The message log level.
 * @param owner[in]   The owner of the message.
 * @param message[in] The message to be loged.
 * @return The number of characters that are loged.
 */
int	log_in(enum e_log_level level, char *owner, char *message)
{
	int	lenght;

	lenght = 0;
	if (level <= current_log_level(-1))
	{
		lenght += s_log_level(level, current_log_fd(-1));
		lenght += s_log_message(current_log_fd(-1), owner, message);
		if (level == ERROR)
		{
			perror("System error");
			exit(EXIT_FAILURE);
		}
	}
	return (lenght);
}

static int	s_log_level(enum e_log_level level, int fd)
{
	if (level == ERROR)
		return (0);
	else if (level == WARNING)
		return (write(fd, "\tWarning: ", 10));
	else if (level == INFO)
		return (write(fd, "\t\tInfo: ", 8));
	else
		return (write(fd, "\t\t\tUnknown Level: ", 18));
}

static int	s_log_owner(int fd, char *owner)
{
	size_t	size;

	size = ft_strlen(owner);
	if (size)
		return (write(fd, owner, size));
	else
		return (write(fd, "unknown owner", 13));
}

static int	s_log_message(int fd, char *owner, char *message)
{
	size_t	lenght;
	size_t	size;

	lenght = write(fd, "(", 1);
	lenght += s_log_owner(fd, owner);
	lenght += write(fd, ") ", 2);
	size = ft_strlen(message);
	if (size)
		lenght += write(fd, message, size);
	lenght += write(fd, "\n", 1);
	return (lenght);
}
