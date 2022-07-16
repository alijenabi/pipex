/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:35:15 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <stdlib.h>

/**
 * Iterates the list ’lst’ and applies the function f’ on the content of each 
 * node. Creates a new list resulting of the successive applications of the 
 * function ’f’.  The ’del’ function is used to delete the content of a node 
 * if f fails at a point during mapping.
 * @param lst[in, out] The address of a pointer to a node.
 * @param f[in]        The address of the function used to iterate on the list.
 * @param del[in]      The address of the function used to delete the content
 *                      of a node if f fails at an element.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*itr;

	if (!lst)
		return (NULL);
	ans = NULL;
	while (lst)
	{
		itr = ft_lstnew(f(lst->content));
		if (!itr)
		{	
			if (del)
				ft_lstclear(&itr, del);
			return (NULL);
		}
		ft_lstadd_back(&ans, itr);
		lst = lst->next;
	}
	return (ans);
}
