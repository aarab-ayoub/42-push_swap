#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
// typedef struct s_stack
// {
// 	int nbr;
// 	struct s_stack *next;
// } t_stack;


// void	push(t_stack **s1, t_stack **s2)
// {
// 	t_stack *head;
	
// 	if (!s2)
// 		return ;
	
// 	head = (*s2);
// 	(*s2) = (*s2 )->next;
// 	head->next = (*s1);
// 	(*s1) = head;	 
// }

// void	rotate(t_stack **stack)
// {
// 	t_stack	*tmp;
// 	t_stack	*last;

// 	if (!*stack || !(*stack)->next)
// 		return ;
// 	tmp = *stack;
// 	last = ft_lstlast(*stack);
// 	*stack = (*stack)->next;
// 	tmp->next = NULL;
// 	last->next = tmp;
// }

#include "push_swap.h"

int ft_lstsize(t_stack *lst)
{
    int count = 0;
    while (lst)
    {
        count++;
        lst = lst->next;
    }
    return count;
}

int main()
{
	t_stack *stack_a = malloc(sizeof(t_stack));
	stack_a->nbr = 1;
	stack_a->next = malloc(sizeof(t_stack));
	stack_a->next->nbr = 2;
	stack_a->next->next = malloc(sizeof(t_stack));
	stack_a->next->next->nbr = 3;
	stack_a->next->next->next= malloc(sizeof(t_stack));
	stack_a->next->next->next->nbr = 0;
	stack_a->next->next->next->next = malloc(sizeof(t_stack));
	stack_a->next->next->next->next->nbr = 4;

	// t_stack *stack_b = malloc(sizeof(t_stack));
	// stack_b->nbr = 3;
	// stack_b->next = malloc(sizeof(t_stack));
	// stack_b->next->nbr = 4;
	// stack_b->next->next = malloc(sizeof(t_stack));
	// stack_b->next->next->nbr = 5;

	// push(&stack_a, &stack_b);
	// while (stack_b)
	// {
	// 	printf("%d\n", stack_b->nbr);
	// 	stack_b = stack_b->next;
	// }
	// rotate(&stack_a);

	int len = ft_lstsize(stack_a);
    int min = stack_a->nbr;
	t_stack *content = stack_a;

    while (content->next && len > 2)
    {
        if (content->nbr < min)
        {
            min = content->nbr;
        }
        content = content->next;
	}
	printf("%d",min);
	return 0;

}