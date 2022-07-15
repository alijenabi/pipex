/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:03:19 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:29:30 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"

char	*ft_str_toupper(char *str)
{
	char	*itr;

	itr = str;
	while (*itr)
	{
		*itr = ft_toupper(*itr);
		itr++;
	}
	return (str);
}
