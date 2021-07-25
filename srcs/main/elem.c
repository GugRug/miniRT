#include "minirt.h"

t_elem	*lst_elem_new(t_type type)
{
	t_elem *new;

	if (!(new = (t_elem*)ft_calloc(1, sizeof (t_elem))))
		return (NULL);
	new->type = type;
	new->res.declared = false;
	new->amb_light.declared = false;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	lst_elem_add_back(t_elem **lst, t_elem *new)
{
	t_elem	*tmp;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		tmp = lst_elem_last(*lst);
		new->prev = tmp;
		tmp->next = new;
	}
}

void	lst_elem_cut(t_elem *elem)
{
	if (elem->prev)
		elem->prev->next = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
}

t_elem	*lst_elem_last(t_elem *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lst_elem_clear(t_elem **lst)
{
	t_elem	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = tmp;
	}
	*lst = NULL;
}
