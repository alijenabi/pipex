/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_if_null.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:01:38 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/22 21:20:32 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printf_if_null(void *ptr)
{
	static char	*null = "(null)";

	if (!ptr)
	{
		write(1, null, 6);
		return (6);
	}
	return (0);
}
