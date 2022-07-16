/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:14:15 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <stdlib.h>

/**
 * Calculates the maximum length of the string required for allocating memory 
 * for the answer of ft_substr(3).
 * @param s[in]   The start of the substring.
 * @param len[in] The maximum length of the substring.
 * @note The s should start at the 'start' of 's' in ft_substr(3).
 */
size_t	st_max_len(char const *s, size_t len)
{
	size_t	ans;

	ans = ft_strlen(s);
	if (len < ans)
		return (len + 1);
	return (ans + 1);
}

/**
 * Allocates (with malloc(3)) and returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’.
 * @param s[in]     The string from which to create the substring.
 * @param start[in] The start index of the substring in the string ’s’.
 * @param len[in]   The maximum length of the substring.
 * @return The substring and NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const char	*ans;
	char		*itr;

	if (!s)
		return (NULL);
	while (*s && start)
	{
		start--;
		s++;
	}
	ans = malloc(st_max_len(s, len) * sizeof(char));
	if (!ans)
		return (0);
	itr = (char *)ans;
	while (*s && len)
	{
		*itr = *s;
		itr++;
		s++;
		len--;
	}
	*itr = '\0';
	return ((char *)ans);
}
