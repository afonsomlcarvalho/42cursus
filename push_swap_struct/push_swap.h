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
#endif