/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:09:14 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:25:43 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"

/**
 * These functions check whether character c, which must have the value of an 
 * unsigned char or EOF, is an alphanumeric character
 * @param c[in] The character.
 * @return true (1) if c is alphanumeric and false (0) otherwise.
 */
int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
