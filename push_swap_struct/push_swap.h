#ifndef PUSH_SWAP_H	
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef	struct list
{
	long int	number;
	struct list	*next;
}	stack;

void	push(stack **a, stack **b, char c);
void	swap(stack **a, char c);
void	rotate(stack **a, char c);
void	printer(stack *a, stack *b);
void	reverse_rotate(stack **a, char c);
int		stack_size(stack *a);
void	sorter(stack *a, stack *b);
int		sorted(stack *a);
stack	*stc_last(stack *a);
void	sort_three(stack **a);
int		min_position(stack *a);
void	sort_four_to_five(stack **a, stack **b);
#endif