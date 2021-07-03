#include "minirt.h"

void	set_rt(t_rt *rt)
{
	char	*line;
	int		gnl;

	gnl = get_next_line(rt->fd, &line);
	printf("--%s--\n", line);
	clean_extra_space(line);
	while (line && gnl > 0)
	{
		set_rt_line_element(&rt->scene->elem, line);
		free(line);
		gnl = get_next_line(rt->fd, &line);
		if (gnl <= 0)
			free(line);
	}
		printf("element gnl: |%d|\n", gnl);
}

void	set_rt_line_element(t_elem **elem, char *line)
{
	int		j;
	char	**splitted;
	t_elem	*element;
	static char	*valid[9] = {"R ", "A ", "c ", "l ", "sp", "pl", "sq", "cy", "tr"};

	j = 0;
	while (valid[j] != NULL)
	{
		if (!ft_strncmp(valid[j], line, 2))
		{
			element = lst_elem_new(j);
			lst_elem_add_back(elem, element);
			break;
		}
		j++;
	}
	splitted = ft_split(line, ' ');
	set_rt_element_content(lst_elem_last(*elem), splitted);
	free(splitted);
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
	while (line[i] != '\0' && line)
	{
		if (line[i] == ' ' && i > 0 && line[i - 1] == ' ')
			ft_memmove(&line[i - 1], &line[i], ft_strlen(line));
		i++;
	}
}
