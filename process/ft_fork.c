/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:54:08 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/06 00:55:18 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processor.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Forks the child process to a new process line. 
 * 
 * @param parent  The parrent process.
 * @param child   The child process.
 * @param cmd     The command to be passed to the child process.
 */
void	ft_fork(void (*parent)(), void (*child)(const char *), const char *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		child(cmd);
	else
	{
		wait(&pid);
		parent();
	}
}
