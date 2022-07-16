/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:24:53 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/06 00:51:48 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSOR_H
# define PROCESSOR_H

void	ft_fork(void (*parent)(), void (*child)(const char *), const char *cmd);
int		process(int read_fd, int write_fd, const char *command);
int		process_heredoc(const char *limiter);

#endif // PROCESSOR_H
