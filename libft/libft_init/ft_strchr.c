/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:47:00 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"

/**
 * Searhes for the character c on s from the beginning of s.
 * @param s[in] The string to search in.
 * @param c[in] The character to search for.
 * @return A pointer to the matched character or NULL if the character is not
 *         found.
 * @note The terminating null byte is considered part of the string, so that if
 *       c is specified as '\0', these functions return a pointer to the 
 *       terminator.
 */
char	*ft_strchr(const char *s, int c)
{
	const int	isascii = ft_isascii(c);

	while (*s && *s != c && isascii)
		s++;
	while (*s == c || !isascii)
		return ((char *)s);
	return (0);
}
