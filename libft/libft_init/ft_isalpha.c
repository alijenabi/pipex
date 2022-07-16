/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:50:22 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 12:51:31 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * These functions check whether character c, which must have the value of an 
 * unsigned char or EOF, is an alphabetic character
 * @param c[in] The character.
 * @return true (1) if c is alphabetic and false (0) otherwise.
 */
int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}
