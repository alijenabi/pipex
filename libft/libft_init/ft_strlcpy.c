/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:42:31 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 14:10:05 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * Copies up to size - 1 characters from the NUL-terminated string src to dst, 
 * while NUL-terminating the result.
 * @param dst[in, out] The destination string.
 * @param src[in]      The source string.
 * @param dstsize[in]  The size of the characters to copy from src to dst.
 * @return The total length of the string they tried to be created (i.e., 
 *         length of src.)
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	itr;

	itr = 0;
	if (dstsize > 0)
	{
		while (itr < dstsize - 1 && src[itr])
		{
			dst[itr] = src[itr];
			itr++;
		}
		dst[itr] = '\0';
	}
	while (src[itr])
		itr++;
	return (itr);
}
