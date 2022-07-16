/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:17:19 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 12:53:21 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * These functions check whether character c, which must have the value of an 
 * unsigned char or EOF, is an printable character
 * @param c[in] The character.
 * @return true (1) if c is printable and false (0) otherwise.
 */
int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}
