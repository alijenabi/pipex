/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:59:08 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 14:58:15 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * Searches for the start of the havstack to be the same as needle.
 * @param havstack[in] The base of the search.
 * @param needle[in]   The frase to search for.
 * @param len[in]      The length of the search in characters.
 * @return true(1) if the havstack is start is matches needle, 
 *         false(0) otherwise.
 */
static int	st_isstarted(const char *havstack, const char *needle, size_t len)
{
	while (*needle && len-- && *havstack == *needle)
	{
		havstack++;
		needle++;
	}
	return (!*needle);
}

/**
 * locates the first occurrence of the null-terminated string needle in the 
 * null-terminated string havstack.
 * @param havstack[in] The base of the search.
 * @param needle[in]   The frase to search for.
 * @param len[in]      The length of the search in characters.
 * @return If needle is an empty string, havstack; if needle occurs nowhere in
 *         havstack, NULL; otherwise a pointer to the first character of the 
 *         first occurrence of needle.
 */
char	*ft_strnstr(const char *havstack, const char *needle, size_t len)
{
	if (needle && !*needle)
		return ((char *)havstack);
	while (*havstack && *needle && len)
	{
		if (st_isstarted(havstack, needle, len))
		{
			return ((char *)havstack);
		}
		len--;
		havstack++;
	}
	return (0);
}
