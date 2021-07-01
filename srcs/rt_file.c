#include "minirt.h"

void	set_rt(t_rt *rt)
{
	char	*line;
	int		gnl;

	gnl = get_next_line(rt->fd, &line);
	clean_extra_space(&line);
	while (line)
	{
		set_rt_line_element(rt, line);
		free(line);
		if (gnl <= 0)
			break;
		gnl = get_next_line(rt->fd, &line);
	}
}

void	set_rt_line_element(t_elem *elem, char *line)
{
	int	i;
	int	j;
	char **splitted;
	t_elem *element;
	static char	*valid[9] = {"R ", "A ", "c ", "l ", "sp", "pl", "sq", "cy", "tr"};

	i = 0;

	while (line[i] != '\n')
	{
		j = 0;
		while (valid != NULL)
		{
			if (!ft_strncmp(valid[j], line[i], 2))
			{
				element = lst_elem_new(j);
				lst_elem_add_back(elem, element);
			}
			j++;
		}
		i++;
	}
	splitted = ft_split(line, ' ');
	set_rt_element_content(lst_elem_last(elem), splitted);
	//than send to the specific validator to see if each parameter is correct
}

void	set_rt_element_content(t_elem *elem, char **splitted)
{
	if (elem->type == SQUARE)
	{
		set_rt_square(elem, splitted);
	}
}

void	clean_extra_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line)
	{
		if (line[i] == ' ' && i > 0 && line[i - 1] == ' ')
			ft_memmove(&line[i - 1], &line[i], ft_strlen(line) - (i + 1));
		i++;
	}
}
