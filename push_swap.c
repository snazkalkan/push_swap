#include "push_swap.h"

int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
int has_duplicates(t_list **a)
{
	int i;
	t_list *a_tmp;
	t_list *temp;

	a_tmp = *a;
	i = a_tmp->value;
	while (a_tmp->next)
	{
		temp = a_tmp->next;
		while (temp)
		{
			if (temp->value == i)
				return (0);
			temp = temp->next;
		}
		a_tmp = a_tmp->next;
		i = a_tmp->value;
	}
	return (1);
}
int is_valid_input(char *str)
{
	int i = 0;

	// NULL kontrolü
	if (!str || !str[0])
		return (0);

	// Sadece boşluklardan mı oluşuyor?
	while (str[i])
	{
		if (str[i] != ' ')
			break;
		i++;
	}
	if (str[i] == '\0')
		return (0);

	return (1);
}
int is_valid_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return 1;
}
t_list  *new_node(int value)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void    append_node(t_list **head, int value)
{
    t_list *new = new_node(value);
    t_list *tmp;
    if (!new)
        return ;
    if (!*head)
    {
        *head = new;
        return ;
    }
    tmp = *head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

t_list *parse_arguments(char **av)
{
	t_list *stack = NULL;
	char **split;
	int i;
	int j;
	int value;

	i = 0;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (NULL);
		j = 0;
		while (split[j])
		{
			if (!is_valid_number(split[j]))
			{
				ft_putstr("error\n");
				exit(1);
			}
			value = ft_atol(split[j]);
			append_node(&stack, value);
            free(split[j]);
            j++;
        }
        free(split);
        i++;
    }
	if (!has_duplicates(&stack))
	{
		ft_putstr("error\n");
		exit(1);
	}
	return (stack);
}

void    free_list(t_list *head)
{
    t_list *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void print(t_list *stack)
{
	while (stack)
	{
		printf("(%d)->", stack->value);
		stack = stack->next;
	}
	printf("NULL");
	printf("\n");
}

// void push_all_b_to_a(t_stack *stack)
// {
// 	int index;
// 	int target_idx;

// 	target_idx = target_index(stack->a, target_node_b_to_a(stack->a, node_b->value));
// 	while (stack->b)
// 	{
// 		push_b_to_a(a, b, )
// 	}
// }

// int main(int ac, char **av)
// {
// 	t_stack *stack;
// 	stack = malloc(sizeof(t_stack));
// 	if (ac < 2)
// 		return (0);
		
// 	av++;
// 	stack->a = parse_arguments(av);
// 	stack->a_length = ft_lstsize(stack->a);
// 	stack->b_length = ft_lstsize(stack->b);
// 	if (is_it_sorted(stack->a))
//     	return (0);
// 	// if (stack->a_length > 3)
// 		push_b(stack);
// 	// if (stack->a_length > 3)
// 		push_b(stack);
// 	while (stack->a_length > 3)
// 	{
// 		cost_count(&stack->a, &stack->b);
// 		push_b(stack);
// 	}
// 	if (stack->a_length == 3)
// 		sort_three(&stack->a);
	
// 	// cost_count_b_to_a(&stack->b, &stack->a);
// 	printf("stack a:   ");
// 	print(stack->a);
// 	printf("stack b:   ");
// 	print(stack->b);
// }

int main(int ac, char **av)
{
	t_stack *stack;
	stack = malloc(sizeof(t_stack));
	if (ac < 2 || !is_valid_input(av[1]))
		return (0);
	av++;
	stack->a = parse_arguments(av);
	stack->a_length = ft_lstsize(stack->a);
	stack->b_length = ft_lstsize(stack->b);
	if (is_it_sorted(stack->a))
		return (0);
	if (stack->a_length == 2 && !is_it_sorted(stack->a))
	{
		swap_a(stack->a);
		exit (1);
	}
	push_b(stack);
	if (stack->a_length > 3)
		push_b(stack);
	while (stack->a_length > 3)
	{
		cost_count(&stack->a, &stack->b);
		push_b(stack);
	}
	if (stack->a_length == 3)
		sort_three(&stack->a);
	push_b_to_a(&stack->a, &stack->b);
	while (!is_it_sorted(stack->a))
		rotate_a(&stack->a);
	print(stack->a);
	print(stack->b);
}