#ifndef LISTS_H	
# define LISTS_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
#endif