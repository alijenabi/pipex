/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:27:07 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/08 23:19:38 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PAIR_H
# define STACK_PAIR_H
# include "stack_types.h"

t_stack_pair	*duplicate_stack_pair(t_stack_pair pair);
void			destroy_stack_pair(t_stack_pair *pair);
int				is_stack_pair_sorted(t_stack_pair pair);
t_stack_pair	generate_stack_pair(const int length, char *const *items);
void			print_stack_pair(t_stack_pair *pair);

#endif // STACK_PAIR_H
