/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:25:58 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <stdlib.h>

/**
 * Allocates (with malloc(3)) and returns a new string, which is the result 
 * of the concatenation of ’s1’ and ’s2’.
 * @param s1[in] The prefix string.
 * @param s2[in] The suffix string.
 * @return The new string and NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	const char	*ans;
	char		*itr;

	if (!s1 || !s2)
		return (NULL);
	ans = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ans)
		return (0);
	itr = (char *)ans;
	while (*s1)
		*itr++ = *s1++;
	while (*s2)
		*itr++ = *s2++;
	*itr = '\0';
	return ((char *)ans);
}
