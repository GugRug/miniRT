#include "minirt.h"

void	validate_args(int argc, char **argv, t_rt *rt)
{
	if (argc < 1 || argc > 2)
		return;
	if (!argv || !*argv)
		return;
	if (validate_rt_name(argv[1]))
		rt->fd = open(argv[1], O_RDONLY);
	else
		return;
	if (argc == 2 && !ft_strncmp(argv[2], "--save", 7))
		rt->save = true;
	else
		rt->save = false;
	set_rt(&rt);
}

bool	validate_rt_name(char *name)
{
	if (name)	//need to test if is *.rt later
		return true;
}
