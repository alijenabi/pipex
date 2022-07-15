/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:55:56 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 14:46:52 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * scans the initial n bytes of the memory area pointed to by s (stirng) for 
 * the first instance of c. Both c and the bytes of the memory area pointed to
 * by s are interpreted as unsigned char.
 * @param s[in] The string of unsigned chars.
 * @param c[in] The character to search for.
 * @param n[in] The number of string s involved in search.
 * @return A pointer poining to the first acurance of c in s within n 
 *         characters. NULL if not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	while (s && n && *(unsigned char *)s != (unsigned char)c)
	{
		n--;
		s++;
	}
	if (!s || !n)
		return (NULL);
	return ((void *)s);
}
