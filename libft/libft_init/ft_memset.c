/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:46:39 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 13:56:59 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * Fills the first n bytes of the memory area pointed to by s with the constant
 * byte c.
 * @param s[out]  The pointer pointing to the beginning of the memory area.
 * @param c[in]   The filling character.
 * @param len[in] The length of the filling action.
 * @return a pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t len)
{
	char	*itr;

	itr = (char *)s;
	while (len)
	{
		*(unsigned char *)itr = (unsigned char)c;
		itr++;
		len--;
	}
	return (s);
}
