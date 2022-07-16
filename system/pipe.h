/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:08:27 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/05 17:37:18 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

/**
 * @brief Holds the pipe info.
 */
typedef struct s_pipe
{
	int	read_end;
	int	write_end;
}		t_pipe;

void	close_pipe(t_pipe pipe);
t_pipe	get_new_pipe(void);

#endif // PIPE_H
