#include "push_swap.h"

void	rotate_a(t_list **a)
{
	ft_lstadd_back(a, ft_lstnew((*a)->value));
	*a = (*a)->next;
	ft_putstr("ra\n");
}

void	rotate_b(t_list **b)
{
	ft_lstadd_back(b, ft_lstnew((*b)->value));
	*b = (*b)->next;
	ft_putstr("rb\n");
}

void	rotate_a_b(t_list *a, t_list *b)
{
	rotate_a(&a);
	rotate_b(&b);
	ft_putstr("rr\n");
}
t_list *ft_not_last(t_list *a) //sondan bir onceki node
{
	if(!a)
		return (NULL);
	while (a->next->next != NULL)
		a = a->next;
	return(a);
}

// void rev_rotate_b(t_list *b)
// {
// 	t_list *last = ft_lstlast(b);
// 	ft_not_last(b)->next = NULL;
// 	ft_lstadd_front(&b, last);
// 	ft_putstr("rrb\n");
// }

void rev_rotate_b(t_list **b)
{
	t_list *prev = NULL;
	t_list *last = *b;

	if (!b || !*b || !(*b)->next)
		return ;

	// Son elemana kadar ilerle, aynı anda prev'i de takip et
	while (last->next)
	{
		prev = last;
		last = last->next;
	}

	// prev artık sondan bir önceki eleman
	prev->next = NULL;
	last->next = *b;
	*b = last;

	ft_putstr("rrb\n");
}


void rev_rot_a_b(t_list *a, t_list *b)
{
	rev_rotate_a(&a);
	rev_rotate_b(&b);
	ft_putstr("rrr\n");
}

// void rev_rotate_a(t_list **a)
// {
// 	t_list *tmp;

// 	tmp = ft_lstnew((*a)->next->value);
// 	ft_lstadd_front(&tmp, ft_lstnew((*a)->value));
// 	*a = (*a)->next->next;
// 	ft_lstadd_back(a, tmp);
// 	ft_putstr("rra\n");
// }

void rev_rotate_a(t_list **a)
{
	t_list *prev = NULL;
	t_list *last = *a;

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

	ft_putstr("rra\n");
}

void	rr(t_list **a, t_list **b)
{
	rotate_a(a);
	rotate_b(b);
	ft_putstr("rr\n");
}
