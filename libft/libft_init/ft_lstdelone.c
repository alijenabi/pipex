/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:35:49 by alijenabi         #+#    #+#             */
/*   Updated: 2022/06/21 12:24:25 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_init.h"
#include <stdlib.h>

/**
 * Takes as a parameter a node and frees the memory of the node’s content using
 * the function ’del’ given as a parameter and free the node. The memory of 
 * ’next’ must not be freed.
 * @param lst[out] The node to free.
 * @param del[in]  The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		if (lst->content && del)
			del(lst->content);
		free(lst);
	}
}
