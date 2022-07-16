/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:11:27 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/05 17:37:28 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"
#include "../log/logger.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Closes the pipe.
 * 
 * @param pipe The pipe.
 */
void	close_pipe(t_pipe pipe)
{
	close(pipe.read_end);
	close(pipe.write_end);
}

/**
 * @brief Gets a new pipe.
 * 
 * @return The new pipe.
 */
t_pipe	get_new_pipe(void)
{
	t_pipe	current;
	int		pipe_fds[2];

	if (pipe(pipe_fds) == 1)
		log_in(ERROR, "system|ft_pipe(0)", "Cannot open the pipe.");
	current.read_end = pipe_fds[0];
	current.write_end = pipe_fds[1];
	return (current);
}
