/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 05:27:13 by skalkan           #+#    #+#             */
/*   Updated: 2025/04/14 17:14:31 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_list **a)
{
	int		i;
	t_list	*a_tmp;
	t_list	*temp;

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

int	is_valid_num(char *str)
{
	int	i;

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
	return (1);
}

t_list	*new_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	append_node(t_list **head, int value)
{
	t_list	*new;
	t_list	*tmp;

	new = new_node(value);
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

t_list	*parse_arguments(char **av, int i, int j)
{
	t_list	*stack;
	char	**split;
	long	value;

	stack = NULL;
	while (av[++i])
	{
		split = ft_split(av[i], ' ');
		j = -1;
		while (split[++j] == NULL)
			return (putstr("Error\n"), clean(split), lstclear(&stack), NULL);
		j = -1;
		while (split[++j])
		{
			value = ft_atol(split[j]);
			if ((value > INT_MAX || value < INT_MIN) || !is_valid_num(split[j]))
				return (putstr("Error\n"), clean(split), lstclear(&stack), NULL);
			append_node(&stack, value);
		}
		if (split)
			clean(split);
	}
	if (!has_duplicates(&stack))
		return (putstr("Error\n"), lstclear(&stack), NULL);
	return (stack);
}
