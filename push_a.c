/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 05:23:10 by skalkan           #+#    #+#             */
/*   Updated: 2025/04/14 06:46:55 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_index(t_list **a, int index)
{
	while (index-- > 0)
		rotate_a(a);
}

void	rev_rotate_a_to_index(t_list **a, int index)
{
	while (index-- > 0)
		rev_rotate_a(a);
}

void	rotate_b_to_target(t_list **b, int target)
{
	while (*b && (*b)->value != target)
		rotate_b(b);
}

void	rev_rotate_b_to_target(t_list **b, int target)
{
	while (*b && (*b)->value != target)
		rev_rotate_b(b);
}

void	push_a_to_b(t_list **a, t_list **b, int index)
{
	t_list	*tmp;
	int		len;
	int		i;
	int		target;
	int		target_index_b;

	i = -1;
	tmp = *a;
	len = ft_lstsize(*a);
	while (++i < index)
		tmp = tmp->next;
	if (index <= len / 2)
		rotate_a_to_index(a, index);
	else
		rev_rotate_a_to_index(a, len - index);
	target = target_node_a_to_b(b, tmp->value);
	target_index_b = target_index(b, target);
	len = ft_lstsize(*b);
	if (target_index_b <= len / 2)
		rotate_b_to_target(b, target);
	else
		rev_rotate_b_to_target(b, target);
}
