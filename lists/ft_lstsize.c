#include "lists.h"

int	ft_lstsize(t_list *lst)
{
	int	size;
	t_list	*current;

	size = 0;
	current = lst;
	if (!current)
		return (NULL);
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}