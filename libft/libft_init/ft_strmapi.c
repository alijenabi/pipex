/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:47:24 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <stdlib.h>

/**
 * Applies the function ’f’ to each character of the string ’s’, and passing 
 * its index as first argument to create a new string (with malloc(3)) 
 * resulting from successive applications of ’f’.
 * @param s[in] The string on which to iterate.
 * @param f[in]  The function to apply to each character.
 * @return The string created from the successive applications of ’f’. 
 *         Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	const char	*ans;
	char		*itr;

	if (!s)
		return (NULL);
	ans = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ans)
		return (0);
	itr = (char *)ans;
	while (*s && f)
	{
		*itr = f((unsigned int)(itr - ans), *s);
		s++;
		itr++;
	}
	*itr = '\0';
	return ((char *)ans);
}
