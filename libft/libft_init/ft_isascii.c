/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:13:26 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 12:52:12 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * These functions check whether character c, which must have the value of an 
 * unsigned char or EOF, is a 7-bit unsigned char value that fits into the 
 * ASCII character set
 * @param c[in] The character.
 * @return true (1) if c is ASCII and false (0) otherwise.
 */
int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
