/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:45:30 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/04 10:36:34 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"

/**
 * @brief Setst the current log file descriptor.
 * 
 * @param new_fd[in] The new file descriptor, or -1 for reading current fd.
 * @return The current log file descriptor.
 */
int	current_log_fd(int new_fd)
{
	static int	current_fd = 1;

	if (0 < new_fd)
		current_fd = new_fd;
	return (current_fd);
}

/**
 * @brief Sets the current log level.
 * if called with minus values it will give the setted value and does not set 
 * any log level.
 *
 * @param level[in] The setting level, or -1 for reading level.
 * @return The current log level.
 */
enum e_log_level	current_log_level(enum e_log_level level)
{
	static enum e_log_level	current = ERROR;

	if (level != (enum e_log_level)(-1))
		current = level;
	return (current);
}
