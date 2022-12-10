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