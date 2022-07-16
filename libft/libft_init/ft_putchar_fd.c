/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:46:49 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 13:51:11 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * Outputs the character ’c’ to the given file descriptor.
 * @param c[in]   The character to output.
 * @param fd[in]  The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd)
{
	(void)write(fd, &c, sizeof(char));
}
