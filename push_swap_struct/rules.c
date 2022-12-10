#include "push_swap.h"

void	push(stack **a, stack **b, char c)
{
	stack *temp;

	if (!(*a))
		return ;
	if (!(*b))
	{
		*b = malloc(sizeof(stack));
		(*b)->number = (*a)->number;
		(*b)->next = NULL;
	}
	else
	{
		temp = malloc(sizeof(stack));
		temp->number = (*a)->number;
		temp->next = *b;
		*b = temp;
	}
	*a = (*a)->next;
	ft_printf("p%c\n", c);
}

void	swap(stack **a, char c)
{
	long int	swap;

	swap = (*a)->number;
	(*a)->number = (*a)->next->number;
	(*a)->next->number = swap;
	if (c)
		ft_printf("s%c\n", c);
}

void	rotate(stack **a, char c)
{
	stack		*current;
	stack		*temp;

	if ((*a)->next)
	{
		temp = (*a);
		(*a) = (*a)->next;
		current = (*a);
		while (current->next)
			current = current->next;
		temp->next = NULL;
		current->next = temp;
	}
	if (c)
		ft_printf("r%c\n", c);
}

void	reverse_rotate(stack **a, char c)
{
	stack	*last;
	stack	*current;

	if ((*a)->next)
	{
		last = (*a);
		while (last->next)
			last = last->next;
		current = (*a);
		while (current->next->next)
			current = current->next;
		current->next = NULL;
		last->next = (*a);
		(*a) = last;
	}
	if (c)
		ft_printf("rr%c\n", c);
}
