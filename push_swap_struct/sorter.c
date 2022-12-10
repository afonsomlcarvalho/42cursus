#include "push_swap.h"

void	sorter(stack *a, stack *b)
{
	printer(a, b);
	if (stack_size(a) == 2)
		swap(&a, 'a');
	else if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) <= 5)
		sort_four_to_five(&a, &b);
	printer(a, b);
}