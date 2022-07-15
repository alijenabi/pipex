/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:47:43 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/10 18:19:01 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TREE_H
# define STACK_TREE_H
# include "stack_types.h"

t_stack_leaf			*generate_children_of(t_stack_leaf *leaf, int *lenght);
t_stack_leaf			*tree_root(t_stack_pair *pair);
void					print_leaf(t_stack_leaf *leaf);


#endif // STACK_TREE_H
