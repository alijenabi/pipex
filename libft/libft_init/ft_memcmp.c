/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:02:23 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 13:40:47 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * Compares the first n bytes (each interpreted as unsigned char) of the memory
 * areas s1 and s2.
 * @param s1[in] The first string.
 * @param s2[in] The second string.
 * @param n[in] The number of character that should be compared.
 * @return an integer less than, equal to, or greater than zero if the first n
 *         bytes of s1 is found, respectively, to be less than, to match, or be
 *         greater than the first n bytes of s2.
 * @note the sign is determined by the sign of the difference between the first
 *       pair of bytes (interpreted as unsigned char) that differ in s1 and s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n && s1 && s2 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		n--;
		s1++;
		s2++;
	}
	if (!n)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
