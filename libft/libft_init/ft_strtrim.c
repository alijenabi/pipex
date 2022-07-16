/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:36:58 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <stdlib.h>

/**
 * Gives the lenght of the string after triming.
 * @param s1[in]  The string to trim.
 * @param set[in] The set of characters to be trimed.
 * @return Lenght of the string after triming.
 */
static size_t	st_trim_len(char const *s1, char const *set)
{
	char	*itr;
	int		len;

	len = ft_strlen(s1) - 1;
	itr = (char *)&s1[len];
	while (len >= 0 && *itr && ft_strchr(set, *itr--))
		len--;
	if (itr != (char *)&s1[len])
		len++;
	itr = (char *)s1;
	while (len >= 0 && *itr && ft_strchr(set, *itr++))
		len--;
	if (len < 0)
		return (0);
	return (len);
}

/**
 * Allocates (with malloc(3)) and returns a copy of 's1’ with the characters 
 * specified in ’set’ removed from the beginning and the end of the string.
 * @param s1[in]  The string to be trimmed.
 * @param set[in] The reference set of characters to trim.
 * @return The trimmed string and NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*ans;
	char		*ans_itr;
	int			len;

	if (!s1)
		return (NULL);
	len = st_trim_len(s1, set);
	ans = (char *)malloc((len + 1) * sizeof(char));
	if (!ans)
		return (0);
	ans_itr = (char *)ans;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (*s1 && len--)
		*ans_itr++ = *s1++;
	*ans_itr = '\0';
	return ((char *)ans);
}
