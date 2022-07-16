/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:10:50 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:29:24 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"

char	*ft_str_tolower(char *str)
{
	char	*itr;

	itr = str;
	while (*itr)
	{
		*itr = ft_tolower(*itr);
		itr++;
	}
	return (str);
}
