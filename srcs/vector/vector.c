#include "minirt.h"

t_coord	new_point(long double x, long double y, long double z)
{
	t_coord	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_coord	v_add(t_coord v, t_coord u)
{
	return (new_point((v.x + u.x), (v.y + u.y), (v.z + u.z)));
}

t_coord	v_sub(t_coord v, t_coord u)
{
	return (new_point((v.x - u.x), (v.y - u.y), (v.z - u.z)));
}

t_coord	v_scale(t_coord v, double f)
{
	return (new_point((f * v.x), (f * v.y), (f * v.z)));
}

t_coord	v_cross(t_coord v, t_coord u)
{
	return (new_point(((v.y * u.z) - (v.z * u.y)),
						((v.z * u.x) - (v.x * u.z)),
						((v.x * u.y) - (v.y * u.x))));
}

t_vect	v_position(t_coord v, t_coord u, double t)
{
	return (v_add(v, v_scale(u, t)));
}

double	v_dot(t_coord v, t_coord u)
{
	return ((v.x * u.x) + (v.y * u.y) + (v.z * u.z));
}

double	v_len(t_coord v)
{
	return (sqrt(v_len_sqr(v)));
}

double	v_len_sqr(t_coord v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}
