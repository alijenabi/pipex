/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:51:01 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/10 19:29:06 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log/logger.h"
#include "stack/stack.h"
#include "stack/stack_pair_operation.h"
#include "stack/stack_pair.h"
#include "stack/stack_tree.h"
#include "stack/stack_types.h"
#include "libft/libft.h"
#include <stdlib.h>

int st_find_parent_index(t_stack_leaf **leafs, int length, t_stack_leaf *parent)
{
	int	itr;

	itr = 0;
	ft_printf("searching for: %p \n", parent);
	// print_leaf(parent);
	while (itr < length)
	{
		ft_printf("[%i]: %p %p\n", itr, leafs + itr, &(*leafs)[itr]);
		// print_leaf(leafs + itr);
		if ((&(*leafs)[itr]) == parent)
			return (itr);
		itr++;
	}
	return -1;
}

int	st_append_leafs(t_stack_leaf **leafs, int length,
	t_stack_leaf **new_leafs, int new_leaf_length)
{
	t_stack_leaf	*temp;
	int				itr;
	int				parent_index;

	itr = 0;
	while (itr < length)
	{
		ft_printf("[%i]:%p \n", itr, &(*new_leafs)[itr]);
		ft_printf("[%i].parrent: %p \n", itr, (*new_leafs)[itr].parent);
		itr++;
	}
	temp = malloc((length + new_leaf_length) * sizeof(t_stack_leaf));
	if (!temp)
		log_in(ERROR, "main", "Cannot allocate memory.");
	itr = 0;
	parent_index = -1;
	while (itr < length)
	{
		temp[itr] = (*leafs)[itr];
		ft_printf("itr = %i", itr);
		parent_index = st_find_parent_index(leafs, length, (*leafs)[itr].parent);
		if (parent_index == -1 && (*leafs)[itr].parent != tree_root(0))
			log_in(ERROR, "main", "Cannot find the parent.");
		else if (parent_index >= 0)
			temp[itr].parent = &(*leafs)[parent_index];
		itr++;
	}
	while (itr < length + new_leaf_length)
	{
		temp[itr] = (*new_leafs)[itr - length];
		parent_index = st_find_parent_index(leafs, length, (*new_leafs)[itr - length].parent);
		if (parent_index == -1 && (*leafs)[itr].parent != tree_root(0))
			log_in(ERROR, "main", "Cannot find the parent.");
		else if (parent_index >= 0)
			temp[itr].parent = &temp[parent_index];
		itr++;
	}
	ft_printf("\n\n\n");
	itr = 0;
	while (itr < length + new_leaf_length)
	{
		ft_printf("[%i]:%p \n", itr, &(temp)[itr]);
		ft_printf("[%i].parrent: %p \n", itr, (temp)[itr].parent);
		itr++;
	}
	free(*leafs);
	free(*new_leafs);
	*leafs = temp;
	return (length + new_leaf_length);
}

int	main(int argc, char *const *argv)
{
	t_stack_pair 	initial_stack_pair;
	t_stack_leaf    *root;
	t_stack_leaf	*leafs;
	t_stack_leaf	*new_leafs;
	int				new_leafs_length;
	int				length;
	int				itr;

	// current_log_level(INFO);
	initial_stack_pair = generate_stack_pair(argc - 1, argv + 1);
	tree_root(&initial_stack_pair);

	root = tree_root(0);
	if (is_stack_pair_sorted(*root->pair))
		return (0);
	leafs = generate_children_of(root, &length);
	ft_printf("Root: %p ", root);
	itr = 0;
	while (itr < length)
	{
		ft_printf("[%i]:%p \n", itr, &leafs[itr]);
		ft_printf("[%i].parrent: %p \n", itr, leafs[itr].parent);
		itr++;
	}
	ft_printf("\n");
	itr = 0;
	while (itr < length)
	{
		new_leafs = generate_children_of(leafs + itr, &new_leafs_length);
		length = st_append_leafs(&leafs, length, &new_leafs, new_leafs_length);
		ft_printf("%i/%i\n", itr, length);
		itr++;
	}
	return (0);
}
