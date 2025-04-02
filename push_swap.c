/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudenazkalkan <sudenazkalkan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:47:04 by sudenazkalk       #+#    #+#             */
/*   Updated: 2025/04/02 17:26:12 by sudenazkalk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int is_valid_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit)
		return 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return 0;
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
        return;
    if (!*head)
    {
        *head = new;
        return;
    }
    tmp = *head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

t_list *parse_arguments(char **av)
{
	t_list *stack;
	char **split;
	int i;
	int j;
	int value;

	i = 0;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return NULL;
		j = 0;
		while (split[j])
		{
			if (!is_valid_number(split[j]))
			{
				ft_putstr("error\n");
				exit(1);
			}
			value = ft_atoi(split[j]);
			append_node(&stack, value);
            free(split[j]);
            j++;
        }
        free(split);
        i++;
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

int main(int ac, char **av)
{
	t_list *stack;

	if (ac > 1)
	{
		av++;
		stack = parse_arguments(av);
		free_list(stack);
	}
	else
		ft_putstr("usage ./push_swap <numbers>\n");
}