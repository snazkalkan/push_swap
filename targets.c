/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 05:25:19 by skalkan           #+#    #+#             */
/*   Updated: 2025/04/14 08:23:14 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_node_a_to_b(t_list **b, int a)
{
	int		target;
	int		max;
	int		min;
	t_list	*b_tmp;

	max = INT_MIN;
	min = INT_MAX;
	target = INT_MAX;
	b_tmp = *b;
	while (b_tmp)
	{
		if (b_tmp->value < min)
			min = b_tmp->value;
		if (b_tmp->value > max)
			max = b_tmp->value;
		if (b_tmp->value < a
			&& absolute_value(a - b_tmp->value) < absolute_value(a - target))
			target = b_tmp->value;
		b_tmp = b_tmp->next;
	}
	if (a < min)
		target = max;
	return (target);
}

int	target_node_b_to_a(t_list **a, int b)
{
	int		target;
	int		max;
	int		min;
	t_list	*a_tmp;

	max = INT_MIN;
	min = INT_MAX;
	target = INT_MIN;
	a_tmp = *a;
	while (a_tmp)
	{
		if (a_tmp->value > max)
			max = a_tmp->value;
		if (a_tmp->value < min)
			min = a_tmp->value;
		if (a_tmp->value > b
			&& absolute_value(b - a_tmp->value) < absolute_value(b - target))
			target = a_tmp->value;
		a_tmp = a_tmp->next;
	}
	if (b > max)
		return (min);
	return (target);
}

int	target_index(t_list **ab, int i)
{
	int		j;
	t_list	*tmp;

	tmp = *ab;
	j = 0;
	while (tmp)
	{
		if (tmp->value == i)
			return (j);
		tmp = tmp->next;
		j++;
	}
	return (-1);
}
