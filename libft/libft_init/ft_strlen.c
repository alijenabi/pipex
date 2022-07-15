/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:39:31 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 14:12:32 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * Calculates the length of the string s, excluding the terminating null byte.
 * @param c[in] The null terminated string.
 * @return The lenght of the string.
 */
size_t	ft_strlen(const char *c)
{
	const char	*s;

	s = (char *)c;
	while (*c != '\0')
		c++;
	return (c - s);
}
