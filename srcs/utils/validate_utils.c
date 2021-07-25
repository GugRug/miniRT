#include "minirt.h"

int	strarray_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	validate_unit_range(double a, double b, double c)
{
	if (a >= -1 && b >= -1 && c >= -1 && a <= 1 && b <= 1 && c <= 1)
		return (true);
	return (false);
}

bool	validate_posit(double a, double b, double c)
{
	if (a >= 0 && b >= 0 && c >= 0)
		return (true);
	return (false);
}

bool	valid_float(const char *str)
{
	bool	is_float;
	bool	dot;
	int		i;

	i = 0;
	is_float = true;
	dot = false;
	while (str[i])
	{
		if (i == 0)
			is_float &= (ft_isdigit(str[i]) | (str[i] == '+')
					| (str[i] == '-'));
		else
			is_float &= (ft_isdigit(str[i]) | (str[i] == '.'));
		if (str[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		i++;
	}
	return (is_float);
}

bool	valid_int(const char *str)
{
	bool	is_int;
	int		i;

	i = 0;
	is_int = true;
	while (str[i])
	{
		if (i == 0)
			is_int &= (ft_isdigit(str[i]) | (str[i] == '+') | (str[i] == '-'));
		else
			is_int &= (ft_isdigit(str[i]));
		i++;
	}
	return (is_int);
}
