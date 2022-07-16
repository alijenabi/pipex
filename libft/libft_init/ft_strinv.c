/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:54:39 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:29:31 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <stdlib.h>

char	*ft_strinv(char *str)
{
	char	*temp;
	int		itr;
	int		len;

	itr = 0;
	len = ft_strlen(str);
	temp = ft_strdup(str);
	while (itr < len)
	{
		str[itr] = temp[len - 1 - itr];
		itr++;
	}	
	free(temp);
	return (str);
}
