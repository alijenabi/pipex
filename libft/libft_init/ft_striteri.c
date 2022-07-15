/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:38:10 by alijenabi         #+#    #+#             */
/*   Updated: 2022/05/05 15:24:47 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Applies the function ’f’ on each character of the string passed as argument, 
 * passing its index as first argument. Each character is passed by address to
 * ’f’ to be modified if necessary.
 * @param s[in, out] The string on which to iterate.
 * @param f[in]      The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		index;

	if (!s || !f)
		return ;
	index = 0;
	while (*s)
		f(index++, s++);
}
