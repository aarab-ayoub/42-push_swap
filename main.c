#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int data;
	struct s_stack *next;
} t_stack;


void	push(t_stack **s1, t_stack **s2)
{
	t_stack *head;
	
	if (!s2)
		return ;
	
	head = (*s2);
	(*s2) = (*s2 )->next;
	head->next = (*s1);
	(*s1) = head;	 
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	tmp->next = NULL;
	last->next = tmp;
}

int main()
{
	t_stack *stack_a = malloc(sizeof(t_stack));
	stack_a->data = 1;
	stack_a->next = malloc(sizeof(t_stack));
	stack_a->next->data = 2;
	stack_a->next->next = malloc(sizeof(t_stack));
	stack_a->next->next->data = 3;

	// t_stack *stack_b = malloc(sizeof(t_stack));
	// stack_b->data = 3;
	// stack_b->next = malloc(sizeof(t_stack));
	// stack_b->next->data = 4;
	// stack_b->next->next = malloc(sizeof(t_stack));
	// stack_b->next->next->data = 5;

	// push(&stack_a, &stack_b);
	// while (stack_b)
	// {
	// 	printf("%d\n", stack_b->data);
	// 	stack_b = stack_b->next;
	// }
	rotate(&stack_a);
	return 0;

}