/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 00:43:38 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/10 00:11:16 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TYPES_H
# define STACK_TYPES_H
# include <stddef.h>

/**
 * @brief The stack element.
 * 
 * @param value    The element integer value.
 */
typedef struct s_stack_element
{
	int	value;
}		t_stack_element;

/**
 * @brief The stack.
 * 
 * @param length   The length of the stack.
 * @param elements Array of stack stack elements.
 */
typedef struct s_stack
{
	int				length;
	t_stack_element	*elements;
}					t_stack;

/**
 * @brief The stack pair.
 * 
 * @param a The a stack.
 * @param b The b stack.
 */
typedef struct s_stack_pair
{
	t_stack	a;
	t_stack	b;
}			t_stack_pair;

/**
 * @brief The function pointer alience to the stacks' operation functions.
 */
typedef int(*stack_pair_operation)(struct s_stack_pair *pair);

/**
 * @brief The stack leaf.
 * 
 * @param pair      The stack pair of the leaf.
 * @param parent    The parent leaf, NULL if it is root.
 * @param operation The operation on the parent pair to get the current pair.
 */
typedef struct s_stack_leaf
{
	t_stack_pair			*pair;
	struct s_stack_leaf		*parent;
	stack_pair_operation	operation;
}						t_stack_leaf;

#endif // STACK_TYPES_H
