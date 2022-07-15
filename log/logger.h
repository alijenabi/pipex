/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:37:01 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/04 10:36:12 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H
# include <stdarg.h>

/**
 * @brief The logging levels
 * - error 				
 * 		The error logging level, logs only the errors.
 * - warning 			
 * 		The warning logging level, logs both the error and warning level messages
 * - info 				
 * 		The info logging level, logs all of the messages.
 */
enum e_log_level
{
	ERROR,
	WARNING,
	INFO,
};

int					current_log_fd(int new_fd);
enum e_log_level	current_log_level(enum e_log_level level);
int					log_in(enum e_log_level level, char *owner,	char *message);

#endif