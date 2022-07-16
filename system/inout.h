/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inout.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:10:24 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/05 17:51:14 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INOUT_H
# define INOUT_H

enum e_reading_source
{
	READ_FROM_FILE = 0,
	WRITE_TO_FILE = 1,
	APPEND_TO_FILE = 2,
};

void	read_from(int fd);
void	write_to(int fd);
int		file_fd(const char *file_path, enum e_reading_source source);

#endif // INOUT_H
