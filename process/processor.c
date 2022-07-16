/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:27:07 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/06 00:51:40 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processor.h"
#include "../log/logger.h"
#include "../system/environment.h"
#include "../system/inout.h"
#include "../system/pipe.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Defines if the current line is the limiter or not.
 * 
 * @param current_line The current line.
 * @param limiter      The limiter.
 * @return 1 if the current line is the limiter, 0 otherwise.
 */
static int	st_is_limiter(char *current_line, const char *limiter);

/**
 * @brief The dummy function for parrent process.
 */
static void	st_parent(void);

/**
 * @brief Process a command.
 * 
 * @param command The command.
 */
static void	st_process(const char *command);

/**
 * @brief Executes a process.
 * 
 * @param read_fd The process read file descriptor.
 * @param write_fd The process write file descriptor or -1 to write to a pipe.
 * @param command The command to execute.
 * @return The pipe read file descriptor, -1 if no pipe is created.
 */
int	process(int read_fd, int write_fd, const char *command)
{
	t_pipe	pipe;

	if (read_fd > 0)
		read_from(read_fd);
	else
		log_in(ERROR, "main|st_set_process_enviroment(2)",
			"Cannot read from negative read file descriptor.");
	if (write_fd < 0)
	{
		log_in(INFO, "main|st_set_process_enviroment(2)", "Creating a pipe.");
		pipe = get_new_pipe();
		write_to(pipe.write_end);
	}
	else
	{
		write_to(write_fd);
		pipe.read_end = -1;
	}
	ft_fork(&st_parent, &st_process, command);
	return (pipe.read_end);
}

static int	st_is_limiter(char *current_line, const char *limiter)
{
	return (ft_strncmp(current_line, limiter, ft_strlen(limiter)) != 0
		|| ft_strlen(current_line) != ft_strlen(limiter) + 1);
}

int	process_heredoc(const char *lmt)
{
	t_pipe	pipe;
	char	*current_line;
	char	*content;
	char	*temp;

	ft_printf("heredoc>");
	current_line = get_next_line(STDIN_FILENO);
	content = NULL;
	while (st_is_limiter(current_line, lmt))
	{
		ft_printf("heredoc>");
		temp = content;
		if (!content)
			content = "";
		content = ft_strjoin(content, current_line);
		if (temp)
			free(temp);
		free(current_line);
		current_line = get_next_line(STDIN_FILENO);
	}
	pipe = get_new_pipe();
	read_from(STDOUT_FILENO);
	write_to(pipe.write_end);
	ft_printf("%s", content);
	return (pipe.read_end);
}

static void	st_parent(void)
{
	log_in(INFO, "Process|parrent", "Process ended.");
}

static void	st_process(const char *command)
{
	char	*exacutable_name;
	char	*exacutable_path;

	exacutable_name = ft_substr((char *)command, 0,
			ft_strchr((char *)command, ' ') - command);
	exacutable_path = where_is(exacutable_name);
	if (!exacutable_path)
		log_in(ERROR, "process|process(1)", "Cannot find exacutable path.");
	if (execve(exacutable_path,
			ft_split(command, ' '), env_variables(NULL)) == -1)
		log_in(ERROR, "process|process(1)", "Cannot exacute the command.");
	free(exacutable_name);
	free(exacutable_path);
}
