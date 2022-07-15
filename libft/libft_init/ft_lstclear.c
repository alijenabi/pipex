/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:46:34 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <stdlib.h>

/**
 * Deletes and frees the given node and every successor of that node, using 
 * the function ’del’ and free(3). Finally, the pointer to the list must be 
 * set to NULL.
 * @param lst[in, out] The address of a pointer to a node.
 * @param del[in]      The address of the function used to delete the content 
 *                     of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	next = 0;
	while (*lst && (*lst)->next)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
	ft_lstdelone(*lst, del);
	*lst = (0);
}
