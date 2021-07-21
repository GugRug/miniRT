#include "minirt.h"

t_coord	new_point(double x, double y, double z)
{
	t_coord	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vect	v_scale(t_vect v, double f)
{
	return (new_point((f * v.x), (f * v.y), (f * v.z)));
}

double	v_len(t_vect v)
{
	return (sqrt(v_len_sqred(v)));
}

double	v_len_sqred(t_vect v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vect	v_norm(t_vect v)
{
	return (v_scale(v, 1 / v_len(v)));
}
