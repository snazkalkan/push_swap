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

void sort_three(t_list **a)
{
	int first = (*a)->value;
	int second = (*a)->next->value;
	int third = (*a)->next->next->value;

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
// amac: a değerinden küçük olan b elemanları arasında, a’ya en yakın olanını bulmak.
int target_node_a_to_b(t_list **b, int a) //_closest_lower_than_a_in_b 
{
	int target;
	int max;
	int min;
	t_list *b_tmp;

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
		if (b_tmp->value < a && absolute_value(a - b_tmp->value) < absolute_value(a - target))
			target = b_tmp->value;
		b_tmp = b_tmp->next;
	}
	if (a < min)
		target = max;
	return (target);
} 

int target_node_b_to_a(t_list **a, int b) // closest_greater_than_b_in_a
{
	int target;
	int max;
	int min;
	t_list *tmp;

	max = INT_MIN;
	min = INT_MAX;
	target = INT_MIN;
	tmp = *a;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		if (tmp->value < min)
			min = tmp->value;
		if (tmp->value > b && absolute_value(b - tmp->value) < absolute_value(b - target))
			target = tmp->value;
		tmp = tmp->next;
	}
	if (b > max)
		return (min);
	return (target);
}
int target_index(t_list **ab, int i)
{
	int j;
	t_list *tmp;

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

// void	push_a_to_b(t_list **a, t_list **b, int index)
// {
// 	t_list *tmp;
// 	int target;

// 	tmp = *a;
// 	while (index > 0)
// 	{
// 		rotate_a(a);
// 		index--;
// 	}
// 	target = target_node_a_to_b(b, (*a)->value);
// 	if (*b && (*b)->value != target)
// 	{
// 		int b_size = ft_lstsize(*b);
// 		int target_pos = target_index(b, target);
// 		if (target_pos <= b_size / 2)
// 		{
// 			while ((*b)->value != target)
// 				rotate_b(b);
// 		}
// 		else
// 		{
// 			while ((*b)->value != target)
// 				rev_rotate_b(*b);
// 		}
// 	}
// 	t_stack tmp_stack;
// 	tmp_stack.a = *a;
// 	tmp_stack.b = *b;
// 	push_b(&tmp_stack);
// 	*a = tmp_stack.a;
// 	*b = tmp_stack.b;
// }


// void	push_a_to_b(t_list **a, t_list **b, int index)
// {
// 	t_list *temp;
// 	t_list *tmp;
// 	int target;

// 	temp = *b;
// 	tmp = *a;
// 	target = target_node_a_to_b(b, tmp->value);
// 	while ((index))
// 	{
// 		rotate_a(a);
// 		tmp = tmp->next;
// 		index--;
// 	}
// 	while ((*b)->value != target)
// 		rotate_b(b);
// 	t_stack tmp_stack;
// 	tmp_stack.a = *a;
// 	tmp_stack.b = *b;
// 	push_b(&tmp_stack);
// }

// void	push_a_to_b(t_list **a, t_list **b, int index)
// {
// 	t_list *temp;
// 	t_list *tmp;
// 	int target;

// 	temp = *b;
// 	tmp = *a;
// 	target = target_node_a_to_b(b, tmp->value);

// 	while ((index))
// 	{
// 		rotate_a(a);
// 		tmp = tmp->next;
// 		index--;
// 	}
// 	while ((*b)->value != target)
// 		rotate_b(b);
// }


void	push_a_to_b(t_list **a, t_list **b, int index)
{
	t_list *tmp;
	int a_len = ft_lstsize(*a);
	int b_len = ft_lstsize(*b);
	int i = 0;
	int target;
	int target_index_b;

	tmp = *a;
	while (i < index)
	{
		tmp = tmp->next;
		i++;
	} //tmp = pushlanacak eleman
	if (index <= a_len / 2)
	{
		while (index-- > 0)
			rotate_a(a);
	}
	else
	{
		index = a_len - index;
		while (index-- > 0)
		rev_rotate_a(a);
	}
	target = target_node_a_to_b(b, tmp->value);
	target_index_b = target_index(b, target);
	if (target_index_b <= b_len / 2)
	{
		while (*b && (*b)->value != target)
			rotate_b(b);
	}
	else
	{
		while (*b && (*b)->value != target)
			rev_rotate_b(b);
	}
}




int get_rotation_cost(t_list *stack, int index)
{
	int len;
	
	len = ft_lstsize(stack);
	if (index <= len / 2)
		return (index); // rotate
	else
		return (len - index); // reverse rotate
}
void	push_b_to_a(t_list **a, t_list **b)
{
	int target_idx;
	int a_len;
	t_stack stack;
	int target;

	while (*b)
	{
		target = target_node_b_to_a(a, (*b)->value);
		target_idx = target_index(a, target);
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

		// push işlemi
		stack.a = *a;
		stack.b = *b;
		push_a(&stack);
		*a = stack.a;
		*b = stack.b;
	}
}


void cost_count(t_list **a, t_list **b)
{
	int i;
	int cost_a;
	int cost_b;
	int min_total_cost;
	int total_cost;
	int best_index;
	int a_target_inx;
	t_list *a_tmp;
	
	a_tmp = *a;
	cost_a = 0;
	min_total_cost = INT_MAX;
	i = 0;
	total_cost = 0;
	while (a_tmp)
	{
		a_target_inx = target_index(b, target_node_a_to_b(b, a_tmp->value));
		// cost_b = target_index(b, target_node_a_to_b(b, a_tmp->value));
		// if (cost_b == -1)
		cost_a = get_rotation_cost(*a, i);
		cost_b = get_rotation_cost(*b, a_target_inx);
		total_cost = cost_a + cost_b;
		if (total_cost < min_total_cost)
		{
			min_total_cost = total_cost;
			best_index = i;
		}
		a_tmp = a_tmp->next;
		i++;
	}
	push_a_to_b(a, b, best_index);
}

// void cost_count(t_list **a, t_list **b) //a to b
// {
// 	int j;
// 	int i;
// 	int cost_a;
// 	int cost_b;
// 	int total;
// 	t_list *a_tmp;

// 	a_tmp = *a;
// 	cost_a = 0;
// 	j = 0;
// 	i = 0;
// 	total = INT_MAX;
// 	while (a_tmp)
// 	{
// 		cost_b = target_index(b, target_node_a_to_b(b, a_tmp->value));
// 		if (cost_a + cost_b < total)
// 		{
// 			total = cost_a + cost_b;
// 			j = i;
// 		}
// 		cost_a++;
// 		i++;
// 		a_tmp = a_tmp->next;
// 	}
// 	push_a_to_b(a, b, j);
// }

int absolute_value(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}