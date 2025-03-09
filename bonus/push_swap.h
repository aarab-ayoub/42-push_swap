#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/*                            Data Structures                                 */
/* ************************************************************************** */
typedef struct s_stack
{
    int				nbr;
    int				index;
    struct s_stack	*next;
}					t_stack;

/* ************************************************************************** */
/*                            Function Prototypes                             */
/* ************************************************************************** */

/* Parsing Functions */
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

/* Rules Functions */
void				push(t_stack **s1, t_stack **s2);
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);

/* Move Functions */
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

/* Sorting Functions */
int					is_sorted(t_stack **stack_a);
void				sort_dos(t_stack **stack_a);
void				sort_trois(t_stack **stack_a);
void				sort_cinq(t_stack **stack_a, t_stack **stack_b);
void				print_stack(t_stack *stack);
void				sort_big(t_stack **stack_a, t_stack **stack_b);
int					get_max_pos(t_stack *stack);
void				assign_indexes(t_stack *stack);

/* Checker functions */
int check_operations(t_stack **stack_a, t_stack **stack_b);
int execute_operation(char *line, t_stack **stack_a, t_stack **stack_b);

/* Get Next Line Functions */
char				*get_next_line(int fd);
char				*read_and_save(int fd, char *store);
char				*save(char *store);
char				*extract_line(char *store);
size_t				ft_strlen_g(char *s);
char				*ft_strchr_g(char *s, int c);
char				*ft_strjoin(char *s1, char *s2);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

#endif 