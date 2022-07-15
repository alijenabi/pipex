/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:06:32 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 12:52:54 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * These functions check whether character c, which must have the value of an 
 * unsigned char or EOF, is an digit (0 through 9) character
 * @param c[in] The character.
 * @return true (1) if c is digit and false (0) otherwise.
 */
int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
