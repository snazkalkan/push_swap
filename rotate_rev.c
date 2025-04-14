/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:16:02 by skalkan           #+#    #+#             */
/*   Updated: 2025/04/14 14:55:25 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a)
{
	t_list	*first;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	putstr("ra\n");
}

void	rotate_b(t_list **b)
{
	t_list	*first;
	t_list	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = first->next;
	first->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	putstr("rb\n");
}

t_list	*ft_not_last(t_list *a)
{
	if (!a)
		return (NULL);
	while (a->next->next != NULL)
		a = a->next;
	return (a);
}

void	rev_rotate_b(t_list **b)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	last = *b;
	if (!b || !*b || !(*b)->next)
		return ;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	putstr("rrb\n");
}

void	rev_rotate_a(t_list **a)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	last = *a;
	if (!a || !*a || !(*a)->next)
		return ;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	putstr("rra\n");
}
