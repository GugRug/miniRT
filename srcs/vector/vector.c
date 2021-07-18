#include "minirt.h"

t_coord	new_point(double x, double y, double z)
{
	t_coord	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vect	v_add(t_vect v, t_vect u)
{
	return (new_point((v.x + u.x), (v.y + u.y), (v.z + u.z)));
}

t_vect	v_sub(t_vect v, t_vect u)
{
	return (new_point((v.x - u.x), (v.y - u.y), (v.z - u.z)));
}

t_vect	v_scale(t_vect v, double f)
{
	return (new_point((f * v.x), (f * v.y), (f * v.z)));
}

t_vect	v_cross(t_vect v, t_vect u)
{
	return (new_point(((v.y * u.z) - (v.z * u.y)),
						((v.z * u.x) - (v.x * u.z)),
						((v.x * u.y) - (v.y * u.x))));
}

t_vect	v_position(t_vect v, t_vect u, double t)
{
	return (v_add(v, v_scale(u, t)));
}

double	v_dot(t_vect v, t_vect u)
{
	return ((v.x * u.x) + (v.y * u.y) + (v.z * u.z));
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
