#include "minirt.h"

void	draw_square(t_image *img, t_elem *sqr)
{
	//SQUARE

	int end_x, end_y;

	end_x =	sqr->center->x + sqr->side/2;
	end_y = sqr->center->y + sqr->side/2;

	int	i =	sqr->center->x - sqr->side/2;
	int	j = sqr->center->y - sqr->side/2;
	while (i < end_x)
	{
		j = sqr->center->y - sqr->side/2;
		while (j < end_y)
		{
			draw_pixel(img, i, j, sqr->color);
			j++;
		}
		i++;
	}
}

t_elem	*lst_elem_new(t_type type)
{
	t_elem *new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	new->type = type;
	new->next = NULL;
	new->center = (t_coord*)malloc(sizeof(t_coord));
	new->orient_vect = (t_coord*)malloc(sizeof(t_coord));
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
		tmp->next = new;
	}
}

t_elem	*lst_elem_last(t_elem *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}
