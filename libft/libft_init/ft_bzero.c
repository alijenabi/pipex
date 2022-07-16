/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:43:05 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 12:41:44 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/** 
 * The bzero() function erases the data in the n bytes of the memory starting
 * at the location pointed to by s, by writing zeros (bytes containing '\0')
 * to that area.
 * @param s[in] The starting pointer.
 * @param n[in] The number of bytes to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	while (n)
	{
		*(char *)s = 0;
		s++;
		n--;
	}
}
