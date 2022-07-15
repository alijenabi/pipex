/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:16:12 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 14:29:20 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Searchs if the character c is lower case or not.
 * @param c[in] The character.
 * @return True(1) if the c is lower case, false(0) otherwise.
 */
static int	st_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

/**
 * Converts character to its upper case if it is and upper case character.
 * @param c[in] The character.
 * @return Upper case of the character c or the c itself it c is not a upper 
 *         case character.
 */
int	ft_toupper(int c)
{
	if (st_islower(c))
	{
		return (c - ('a' - 'A'));
	}
	return (c);
}
