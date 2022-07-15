/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_operation.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:17:26 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/08 14:43:06 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PAIR_OPERATION_H
# define STACK_PAIR_OPERATION_H
# include "stack_types.h"
# define STACK_PAIR_OPERATION_COUNT 11

stack_pair_operation	*posible_stack_pair_operations(void);
void					print_pair_operation(stack_pair_operation operation);

int						push_a(t_stack_pair *pair);
int						push_b(t_stack_pair *pair);

int						swap_a(t_stack_pair *pair);
int						swap_b(t_stack_pair *pair);
int						swap_both(t_stack_pair *pair);

int						reverse_rotate_a(t_stack_pair *pair);
int						reverse_rotate_b(t_stack_pair *pair);
int						reverse_rotate_both(t_stack_pair *pair);

int						rotate_a(t_stack_pair *pair);
int						rotate_b(t_stack_pair *pair);
int						rotate_both(t_stack_pair *pair);

#endif // STACK_PAIR_OPERATION_H
