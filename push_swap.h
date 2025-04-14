/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:43:03 by skalkan           #+#    #+#             */
/*   Updated: 2025/04/14 15:07:30 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		a_length;
	int		b_length;
}				t_stack;

char	**ft_split(const char *s, char delimiter);
t_list	*parse_arguments(char **av, int i, int j);
long	ft_atol(const char *str);
void	putstr(char *str);
int		ft_isdigit(char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	swap_a(t_list *a);
void	swap_b(t_list *b);
t_list	*ft_lstnew(int content);
void	lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
t_list	*ft_not_last(t_list *a);
void	rev_rotate_a(t_list **a);
void	rev_rotate_b(t_list **b);
void	sort_three(t_list **a);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
int		target_node_a_to_b(t_list **b, int w);
int		target_node_b_to_a(t_list **a, int w);
int		absolute_value(int a);
int		target_index(t_list **ab, int i);
void	cost_count(t_list **a, t_list **b, int cost_a, int cost_b);
int		is_it_sorted(t_list *a);
void	free_list(t_list *head);
void	push_b_to_a(t_list **a, t_list **b);
void	push_a_to_b(t_list **a, t_list **b, int index);
void	clean(char **str);
int		absolute_value(int a);
char	*ft_strdup(const char *s1);

#endif
