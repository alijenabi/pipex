/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:51:01 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/06 00:30:10 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system/inout.h"
#include "system/pipe.h"
#include "log/logger.h"
#include "process/processor.h"
#include "system/environment.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	st_argument_checker(int argc, char const *argv[])
{
	if (argc < 5)
		log_in(ERROR, "main|argument_checker",
			"You need at least 4 arguments.");
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		if (argc < 6)
			log_in(ERROR, "main|argument_checker",
				"You need at least 5 arguments.");
	}
}

int	st_is_here_doc(const char *second_arg)
{
	return (ft_strncmp(second_arg, "here_doc", ft_strlen("here_doc")) == 0
		&& ft_strlen(second_arg) == ft_strlen("here_doc"));
}

int	main(int argc, char const *argv[], char *const *env)
{
	int	itr;
	int	pipe_read_end_fd;

	env_variables(env);
	st_argument_checker(argc, argv);
	itr = 0;
	itr += 3;
	if (st_is_here_doc(argv[1]))
	{
		pipe_read_end_fd = process_heredoc(argv[2]);
		itr++;
	}
	else
		pipe_read_end_fd = process(file_fd(argv[1],
					READ_FROM_FILE), -1, (char *)argv[2]);
	while (itr < argc - 2)
		process(pipe_read_end_fd, -1, (char *)argv[itr++]);
	if (st_is_here_doc(argv[1]))
		pipe_read_end_fd = process(pipe_read_end_fd, file_fd(argv[argc - 1],
					APPEND_TO_FILE), (char *)argv[argc - 2]);
	else
		pipe_read_end_fd = process(pipe_read_end_fd, file_fd(argv[argc - 1],
					WRITE_TO_FILE), (char *)argv[argc - 2]);
	close(pipe_read_end_fd);
	return (0);
}
