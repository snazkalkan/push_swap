/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:23:40 by skalkan           #+#    #+#             */
/*   Updated: 2025/04/14 10:34:59 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_sorted(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->next && tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		swap_a(*a);
	else if (first > second && second > third)
	{
		swap_a(*a);
		rev_rotate_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first < third)
	{
		swap_a(*a);
		rotate_a(a);
	}
	else if (first < second && second > third && first > third)
		rev_rotate_a(a);
}

int	get_rotation_cost(t_list *stack, int index)
{
	int	len;

	len = ft_lstsize(stack);
	if (index <= len / 2)
		return (index);
	else
		return (len - index);
}

void	push_b_to_a(t_list **a, t_list **b)
{
	int		target_idx;
	int		a_len;
	t_stack	stack;

	while (*b)
	{
		target_idx = target_index(a, target_node_b_to_a(a, (*b)->value));
		a_len = ft_lstsize(*a);
		if (target_idx <= a_len / 2)
		{
			while (target_idx-- > 0)
				rotate_a(a);
		}
		else
		{
			target_idx = a_len - target_idx;
			while (target_idx-- > 0)
				rev_rotate_a(a);
		}
		stack.a = *a;
		stack.b = *b;
		push_a(&stack);
		*a = stack.a;
		*b = stack.b;
	}
}

void	cost_count(t_list **a, t_list **b, int cost_a, int cost_b)
{
	int		i;
	int		min_total_cost;
	int		best_index;
	int		a_target_inx;
	t_list	*a_tmp;

	a_tmp = *a;
	min_total_cost = INT_MAX;
	i = 0;
	while (a_tmp)
	{
		a_target_inx = target_index(b, target_node_a_to_b(b, a_tmp->value));
		cost_a = get_rotation_cost(*a, i);
		cost_b = get_rotation_cost(*b, a_target_inx);
		if ((cost_a + cost_b) < min_total_cost)
		{
			min_total_cost = (cost_a + cost_b);
			best_index = i;
		}
		a_tmp = a_tmp->next;
		i++;
	}
	push_a_to_b(a, b, best_index);
}
