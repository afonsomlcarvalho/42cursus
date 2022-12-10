#include "push_swap.h"

void	printer(stack *a, stack *b)
{
	stack *current;

	ft_printf("a: ");
	current = a;
	while (current)
	{
		ft_printf("%d ", current->number);
		current = current->next;
	}
	ft_printf("\nb: ");
	current = b;
	while (current)
	{
		ft_printf("%d ", current->number);
		current = current->next;
	}
	ft_printf("\n");
}

int	stack_size(stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return(i);
}

stack	*stc_last(stack *a)
{
	stack	*last;

	last = a;
	while (last->next)
		last = last->next;
	return (last);
}

int	min_position(stack *a)
{
	int	min;
	int	i;
	int	m;

	i = 0;
	m = 0;
	min = a->number;
	while (a)
	{
		if (a->number < min)
		{
			min = a->number;
			m = i;
		}
		i++;
		a = a->next;
	}
	return (m);
}