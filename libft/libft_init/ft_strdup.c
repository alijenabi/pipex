/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:31:11 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <stdlib.h>

/**
 * Duplicates the string s1.
 * @param s1[in] The string to copy.
 * @return The pointer to the beginning of the dupliated string. NULL if 
 *         alocation fails.
 * @note The duplicated string is located on a new memory.
 */
char	*ft_strdup(const char *s1)
{
	const char	*ans;
	char		*itr;

	ans = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ans)
		return (0);
	itr = (char *)ans;
	while (*s1)
	{
		*itr = *s1;
		itr++;
		s1++;
	}
	*itr = '\0';
	return ((char *)ans);
}
