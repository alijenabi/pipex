/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:17:21 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:25:31 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"

static int	st_isnumber(const char *c)
{
	return ('0' <= *c && *c <= '9');
}

static int	st_isminus(const char *c)
{
	return ('-' == *c);
}

static int	st_issign(const char *c)
{
	return ('+' == *c || st_isminus(c));
}

static int	st_iswhite(const char *c)
{
	if (ft_strchr(" \f\n\r\t\v", *c))
		return (1);
	return (0);
}

/**
 * The atoi() function converts the initial portion of the string pointed to by
 * nptr to int. The behavior is the same as 
 * 			strtol(nptr, NULL, 10); 
 * except that atoi() does not detect errors. 
 * @param str[in] The string to convert;
 * @return The converted value, 0 if not able to convert.
 */
int	ft_atoi(const char *str)
{
	int	itr;
	int	sum;
	int	sign;

	itr = 0;
	sum = 0;
	sign = 1;
	if (!str || !ft_strlen(str))
		return (0);
	while (st_iswhite(&str[itr]))
		itr++;
	if (st_issign(&str[itr]))
	{
		if (st_isminus(&str[itr]))
			sign = -1;
		itr++;
	}
	if (st_issign(&str[itr]))
		return (0);
	while (st_isnumber(&str[itr]))
	{
		sum = sum * 10 + (str[itr] - '0');
		itr++;
	}
	return (sum * sign);
}
