#include "push_swap.h"

void	ft_swap(int *a, int *b, int counter, char array)
{
	int	c[1];

	if (counter > 1)
	{
		c[0] = *a;
		*a = *b;
		*b = c[0];
	}
	if (array)
		ft_printf("s%c\n", array);
}

void	push(int *a, int *b, int *counter_a, int *counter_b)
{
	int	i;

	i = *counter_a;
	if (*counter_b == 0)
		return ;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	while (++i < *counter_b)
		b[i - 1] = b[i];
	(*counter_a)++;
	(*counter_b)--;
}

void	rotate(int *a, int counter_a, char array)
{
	int	i;
	int	c;

	i = 0;
	c = a[0];
	while (++i < counter_a)
		a[i - 1] = a[i];
	a[i - 1] = c;
	if (array)
		ft_printf("r%c\n", array);
}

void	reverse_rotate(int *a, int counter_a, char array)
{
	int	i;
	int	c;

	i = 0;
	c = a[0];
	while (++i < counter_a)
		c = a[i];
	while (--i >= 0)
		a[i] = a[i - 1];
	a[0] = c;
	if (array)
		ft_printf("rr%c\n", array);
}

int	split_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}