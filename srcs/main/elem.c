#include "minirt.h"

void	draw_square(t_image *img, t_elem *sqr)
{
	//SQUARE

	int end_x, end_y;

	end_x =	sqr->square.center.x + sqr->square.side/2;
	end_y = sqr->square.center.y + sqr->square.side/2;

	int	i =	sqr->square.center.x - sqr->square.side/2;
	int	j = sqr->square.center.y - sqr->square.side/2;
	while (i < end_x)
	{
		j = sqr->square.center.y - sqr->square.side/2;
		while (j < end_y)
		{
			draw_pixel(img, i, j, sqr->square.color);
			j++;
		}
		i++;
	}
}

t_elem	*lst_elem_new(t_type type)
{
	t_elem *new;

	if (!(new = (t_elem*)ft_calloc(1, sizeof(t_elem))))
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
