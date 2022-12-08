#include "push_swap.h"

void	ft_swap(int *a, int *b, int counter)
{
	int	c[1];

	if (counter > 1)
	{
		c[0] = *a;
		*a = *b;
		*b = c[0];
	}
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

void	rotate(int *a, int *b, int rule, int counter_a, int counter_b)
{
	int	i;
	int	c;

	if (rule == 6 || rule == 8)
	{
		i = 0;
		c = a[0];
		while (++i < counter_a)
			a[i - 1] = a[i];
		a[i - 1] = c;
	}
	if (rule == 7 || rule == 8)
	{
		i = 0;
		c = b[0];
		while (++i < counter_b)
			b[i - 1] = b[i];
		b[i - 1] = c;
	}
}

void	reverse_rotate(int *a, int *b, int rule, int counter_a, int counter_b)
{
	int	i;
	int	c;

	if (rule == 9 || rule == 11)
	{
		i = 0;
		c = a[0];
		while (++i < counter_a)
			c = a[i];
		while (--i >= 0)
			a[i] = a[i - 1];
		a[0] = c;
	}
	if (rule == 10 || rule == 11)
	{
		i = 0;
		c = b[0];
		while (++i < counter_b)
			c = b[i];
		while (--i > 0)
			b[i] = b[i - 1];
		b[0] = c;
	}
}

int	split_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}