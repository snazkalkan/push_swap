#include "push_swap.h"

// void	swap_a(t_list *a)
// {
// 	int tmp;
// 	int temp;
// 	if (!a)
// 		return ;

// 	temp = a->next->next->value;
// 	tmp = a->value;
// 	a->value = a->next->value;
// 	a->next->value = tmp;
// 	a->next->next = ft_lstnew(temp);
// 	ft_putstr("sa\n");
// }

void	swap_a(t_list *a)
{
	int tmp;

	if (!a || !a->next)
		return ;

	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	ft_putstr("sa\n");
}

void	swap_b(t_list *b)
{
	int tmp;
	if (!b)
		return ;
	tmp = b->value;
	b->value = b->next->value;
	b->next->value = tmp;
	ft_putstr("sb\n");
}

void	swap_a_b(t_list *a, t_list *b)
{
	swap_a(a);
	swap_b(b);
	ft_putstr("ss\n");
}

void	push_a(t_stack *stack)
{
	if (!stack->b)
		return ;
	ft_lstadd_front(&stack->a, ft_lstnew(stack->b->value));
	stack->b = stack->b->next;
	stack->a_length++;
	stack->b_length--;
	ft_putstr("pa\n");
}

void	push_b(t_stack *stack)
{
	if (!stack->a)
		return ;
	ft_lstadd_front(&stack->b, ft_lstnew(stack->a->value));
	stack->a = stack->a->next;
	stack->a_length--;
	stack->b_length++;
	ft_putstr("pb\n");
}
