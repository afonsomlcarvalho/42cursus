#include "checker.h"

void	checker_push(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (!(*a))
		return ;
	if (!(*b))
	{
		*b = malloc(sizeof(t_stack));
		(*b)->number = (*a)->number;
		(*b)->next = NULL;
	}
	else
	{
		temp = malloc(sizeof(t_stack));
		temp->number = (*a)->number;
		temp->next = (*b);
		(*b) = temp;
	}
	temp1 = (*a);
	*a = (*a)->next;
	free(temp1);
}

void	checker_swap(t_stack **a, t_stack **b, int c)
{
	long int	swap;

	if (checker_stack_size(*a) < 2)
		return ;
	swap = (*a)->number;
	(*a)->number = (*a)->next->number;
	(*a)->next->number = swap;
	if (c)
		checker_swap(b, a, 0);
}

void	checker_rotate(t_stack **a, t_stack **b, int c)
{
	t_stack		*current;
	t_stack		*temp;

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
		checker_rotate(b, a, 0);
}

void	checker_reverse_rotate(t_stack **a, t_stack **b, int c)
{
	t_stack	*last;
	t_stack	*current;

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
		checker_reverse_rotate(b, a, 0);
}