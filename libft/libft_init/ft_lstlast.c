/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:17:27 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"

/**
 * Returns the last node of the list.
 * @param lst[in] The beginning of the list.
 * @return Last node of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
