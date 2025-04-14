/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:20:40 by skalkan           #+#    #+#             */
/*   Updated: 2025/04/14 17:27:22 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *a)
{
	int	tmp;

	if (!a || !a->next)
		return ;
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	putstr("sa\n");
}

void	swap_b(t_list *b)
{
	int	tmp;

	if (!b)
		return ;
	tmp = b->value;
	b->value = b->next->value;
	b->next->value = tmp;
	putstr("sb\n");
}

void	push_a(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->b)
		return ;
	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = stack->a;
	stack->a = tmp;
	stack->a_length++;
	stack->b_length--;
	putstr("pa\n");
}

void	push_b(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->a)
		return ;
	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = stack->b;
	stack->b = tmp;
	stack->a_length--;
	stack->b_length++;
	putstr("pb\n");
}
