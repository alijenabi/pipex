/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulong_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:46:06 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:32:11 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_extras.h"
#include "libft_init.h"
#include <stdlib.h>

char	*ft_ulong_to_str(unsigned long number, unsigned long base)
{
	char	*ans;
	char	*temp;
	int		itr;
	int		current;

	temp = (char *)malloc(100 * sizeof(char));
	if (2 > base || base > 36 || !temp)
		return (NULL);
	itr = 0;
	if (number == 0)
		temp[itr++] = '0';
	while (number != 0)
	{
		current = (number % base);
		if (current < 10)
			temp[itr] = current + '0';
		else
			temp[itr] = current - 10 + 'a';
		number /= base;
		itr++;
	}
	temp[itr] = '\0';
	ans = ft_strdup(ft_strinv(temp));
	free(temp);
	return (ans);
}
