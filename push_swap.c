/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 05:31:46 by skalkan           #+#    #+#             */
/*   Updated: 2025/04/14 18:08:45 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_algorithm(t_stack *stack)
{
	push_b(stack);
	if (stack->a_length > 3)
		push_b(stack);
	while (stack->a_length > 3)
	{
		cost_count(&stack->a, &stack->b, 0, 0);
		push_b(stack);
	}
	if (stack->a_length == 3)
		sort_three(&stack->a);
	push_b_to_a(&stack->a, &stack->b);
	while (!is_it_sorted(stack->a))
		rotate_a(&stack->a);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (ac < 2)
		return (free(stack), 1); //boş girdi
	av++;
	stack->a = parse_arguments(av, -1, -1);
	stack->b = NULL;
	if (!stack->a)
		return (free(stack), 0);
	stack->a_length = ft_lstsize(stack->a);
	stack->b_length = ft_lstsize(stack->b);
	if (is_it_sorted(stack->a))
		return (lstclear(&stack->a), lstclear(&stack->b), free(stack), 0);
	if (stack->a_length == 2 && !is_it_sorted(stack->a))
		return (swap_a(stack->a), lstclear(&stack->a),
			lstclear(&stack->b), free(stack), 0);
	turk_algorithm(stack);
	return (lstclear(&stack->a), lstclear(&stack->b), free(stack), 0);
}
