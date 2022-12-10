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
	long int	i;

	if ((*a)->next)
	{
		i = (*a)->number;
		(*a) = (*a)->next;
		current = (*a);
		while (current)
			current = current->next;
		current = malloc(sizeof(stack));
		current->number = i;
		current->next = NULL;
	}
	if (c)
		ft_printf("r%c\n", c);
}