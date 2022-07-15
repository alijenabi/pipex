/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:51:44 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <string.h>

/**
 * Appends the NUL-terminated string src to the end of dst. It will append at 
 * most (size - strlen(dst) - 1) bytes, NUL-terminating the result.
 * @param dst[in, out] The destination string.
 * @param src[in]      The source string.
 * @param dstsize[in]  The length of copy from src to end of dst.
 * @return The total length of the string they tried to be created (i.e., length
 *         of dst plus the length of src.)
 * @note Traverses dstsize characters without finding a NUL, the length of the 
 *       returned string is considered to be dstsize and the destination string
 *       will not be NUL-terminated (since there was no space for the NUL). 
 *       This keeps strlcat() from running off the end of a string.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_itr;
	size_t	src_itr;
	size_t	ans;

	dst_itr = ft_strlen(dst);
	src_itr = 0;
	ans = dst_itr + ft_strlen(src);
	if (dstsize && dst_itr < dstsize)
	{
		while (dst_itr < dstsize - 1 && src[src_itr])
		{
			dst[dst_itr] = src[src_itr];
			dst_itr++;
			src_itr++;
		}
		dst[dst_itr] = '\0';
		return (ans);
	}
	return (ft_strlen(src) + dstsize);
}
