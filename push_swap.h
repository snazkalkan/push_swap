#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <limits.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list *a;
	t_list *b;
	int a_length;
	int b_length;
}				t_stack;

char	**ft_split(const char *s, char delimiter);
long	ft_atol(const char *str);
void	ft_putstr(char *str);
int		ft_isdigit(char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void 	swap_a(t_list *a);
void	swap_b(t_list *b);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	print(t_list *stack);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_a_b(t_list *a, t_list *b);
t_list *ft_not_last(t_list *a); //sondan bir onceki node
void rev_rotate_a(t_list **a);
void rev_rotate_b(t_list **b);
void rev_rot_a_b(t_list *a, t_list *b);
void sort_three(t_list **a);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
int target_node_a_to_b(t_list **b, int w); 
int target_node_b_to_a(t_list **a, int w);
int absolute_value(int a);
int target_index(t_list **ab, int i);
void cost_count(t_list **a, t_list **b);
int	is_it_sorted(t_list *a);
void    free_list(t_list *head);
void	push_b_to_a(t_list **a, t_list **b);
void cost_count_b_to_a(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);



#endif
