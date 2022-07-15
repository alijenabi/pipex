/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:51:53 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/10 18:19:07 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_tree.h"
#include "stack_pair.h"
#include "stack_pair_operation.h"
#include "../log/logger.h"
#include "../libft/libft.h"
#include <stdlib.h>

/**
 * @brief appends a new pair to the leafs.
 * 
 * @param parent[in]      The leafs parrent.
 * @param leafs[in, out]  Address to the leaf array.
 * @param length[in, out] Address to the leaf array length.
 * @param new_pair[in]    The new pair. 
 * @param operation[in]   The operation from parent pair ot the new pair.
 */
void st_append(t_stack_leaf *parent, t_stack_leaf **leafs, int *length,
	t_stack_pair *new_pair, stack_pair_operation operation)
{
	t_stack_leaf	*temp;
	int				itr;

	if (!leafs)
		log_in(ERROR, "stack|generate_children_of(2)", "leaf is NULL.");
	if (!(*leafs))
		*length = 0;
	(*length)++;
	temp = malloc((*length) * sizeof(t_stack_leaf));
	if (!temp)
		log_in(ERROR, "stack|generate_children_of(2)", "Cannot allocate memory.");
	itr = 0;
	while (itr < (*length) - 1)
	{
		temp[itr] = (*leafs)[itr];
		itr++;
	}
	temp[itr].pair = new_pair;
	temp[itr].parent = parent;
	temp[itr].operation = operation;
	free(*leafs);
	*leafs = temp;
}

/**
 * @brief Checks if the leaf is the root or not.
 * 
 * @param leaf The leaf.
 * @return 1 if the leaf is root, 0 otherwise.
 */
int	st_is_root(t_stack_leaf	*leaf)
{
	// if ((leaf->operation && !leaf->parent) || (!leaf->operation && leaf->parent))
	// 	log_in(ERROR, "stack|generate_children_of(2)",
	// 		"Confilict, if leaf has an operation it has to have a parrent and vice versa.");
	return (!leaf->operation && !leaf->parent && leaf->pair);
}

void st_print_result(t_stack_leaf *leaf)
{
	if (st_is_root(leaf))
		return ;
	print_stack_pair(leaf->pair);
	st_print_result(leaf->parent);
	print_pair_operation(*leaf->operation);
}

/**
 * @brief Generates all the children leafs of a given children.
 * The return leafs has a valid operation, where 
 * 
 * @param parent The parent pair. 
 * @param length The length of the children array (return value).
 * @return The array of children.
 */
t_stack_leaf	*generate_children_of(t_stack_leaf *parent, int *length)
{
	t_stack_leaf	*children;
	t_stack_pair	*temp;
	int				itr;

	itr = 0;
	children = 0;
	*length = 0;
	if (!parent)
		log_in(ERROR, "stack|generate_children_of(2)", "Parent is empty.");
	if (!(parent->pair))
		log_in(ERROR, "stack|generate_children_of(2)",
			"Parent stack pair is empty.");
	while (itr < STACK_PAIR_OPERATION_COUNT)
	{
		temp = duplicate_stack_pair(*parent->pair);
		if (posible_stack_pair_operations()[itr](temp))
		{
			st_append(parent, &children,
				length, temp, posible_stack_pair_operations()[itr]);
			if (is_stack_pair_sorted(*temp))
			{
				st_print_result(&children[(*length) - 1]);
				exit(EXIT_SUCCESS);
			}
		}
		else
			destroy_stack_pair(temp);
		itr++;
	}
	itr = 0;
	if (!st_is_root(parent))
	{
		destroy_stack_pair(parent->pair);
		parent->pair = NULL;
	}
	return (children);
}

/**
 * @brief Gives the root of the stack tree.
 * The root will be created on the frist call only.
 * 
 * @param pair The pair to initiate the root with. 
 * @return The root of stack tree.
 * @throw Error if the pair is NULL on initiation.
 * @throw Error if cannot allocate memory on initiation.
 */
t_stack_leaf	*tree_root(t_stack_pair *pair)
{
	static t_stack_leaf	*root = 0;

	if (!root)
	{
		if (!pair)
			log_in(ERROR, "stack|tree_root(1)",
				"Cannot create root without initial stack pair.");
		root = malloc(sizeof(t_stack_leaf));
		if (!root)
			log_in(ERROR, "stack|tree_root(1)", "Cannot allocate memory.");
		root->pair = pair;
		root->parent = NULL;
		root->operation = NULL;
		log_in(INFO, "stack|tree_root(1)", "Root created successfully.");
	}
	return (root);
}

/**
 * @brief Prints a leaf to stdout.
 * 
 * @param leaf The leaf.
 */
void print_leaf(t_stack_leaf *leaf)
{
	if (st_is_root(leaf))
		ft_printf("ROOT LEAF:\n");
	if (leaf->pair)
		print_stack_pair(leaf->pair);
	else
		ft_printf("Empty stack pair\n");
	if (leaf->operation && *(leaf->operation))
	{
		ft_printf("Operation: ");
		print_pair_operation(*(leaf->operation));
	}
}
