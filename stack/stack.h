/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:22:50 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/08 14:48:34 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "stack_types.h"

void	destroy_stack(t_stack stack);
t_stack	duplicate_stack(t_stack stack);
int		is_stack_sorted(t_stack stack);
t_stack	generate_stack(const int length, char *const *items);
void	print_stack(t_stack *stack);

#endif // STACK_H
