/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:21:05 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 14:28:36 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Searchs if the character c is upper case or not.
 * @param c[in] The character.
 * @return True(1) if the c is upper case, false(0) otherwise.
 */
static int	st_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

/**
 * Converts character to its lower case if it is and upper case character.
 * @param c[in] The character.
 * @return Lower case of the character c or the c itself it c is not a upper 
 *         case character.
 */
int	ft_tolower(int c)
{
	if (st_isupper(c))
	{
		return (c + ('a' - 'A'));
	}
	return (c);
}
