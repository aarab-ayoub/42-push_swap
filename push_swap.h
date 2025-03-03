/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:30:47 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/03 01:15:44 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;

}					t_stack;

typedef struct s_cost
{
	int				cost_a;
	int				cost_b;
	int				total_cost;
	int				target;
}					t_cost;

int					ft_atoi(const char *str);
int					ft_isdigit(int c);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
void				ft_lstclear(t_stack **lst, void (*del)(int));
t_stack				*ft_lstlast(t_stack *lst);
t_stack				*ft_lstnew(int content);
int					ft_lstsize(t_stack *lst);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_split(char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strlen(const char *str);
int					is_delimiter(char c);
char				*ft_strchr(const char *s, int c);
int					is_duplicate(int *tab, int nbr, int pos);
int					is_valid_int(const char *str);
void				free_split(char **split);
int					count_split_args(char **split);

int					parse_numbers(int argc, char **argv, int *arr);
int					count_numbers(int argc, char **argv);

// rules
void				push(t_stack **s1, t_stack **s2);
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);

// moves
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// sorting
int					is_sorted(t_stack **stack_a);
void				sort_dos(t_stack **stack_a);
void				sort_trois(t_stack **stack_a);
void				sort_cinq(t_stack **stack_a, t_stack **stack_b);
void				print_stack(t_stack *stack);

void				sort_big(t_stack **stackA, t_stack **stackB);
void				final_rotate(t_stack **stackA, t_stack **stackB);
void				push_all_to_b(t_stack **stackA, t_stack **stackB);

void				apply_moves(t_stack **stackA , t_stack **stackB);
// void 				cal_costs(t_stack **stackB , t_stack **stackA , t_cost *cost);
void				find_cheapest(t_stack **stack);

#endif