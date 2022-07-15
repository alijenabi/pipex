/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:17:49 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <unistd.h>

/**
 * Outputs the integer 'n' to the given file desciptor.
 * @param s[in]   The integer to output.
 * @param fd[in]  The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd)
{
	const char	*min = "-2147483648";
	char		c;

	if (n == -2147483648)
	{
		(void)write(fd, min, 11 * sizeof(char));
		return ;
	}
	if (n < 0)
	{
		(void)write(fd, "-", sizeof(char));
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		(void)write(fd, &c, sizeof(char));
	}
	else
	{
		c = n % 10 + '0';
		(void)write(fd, &c, sizeof(char));
	}
	return ;
}
