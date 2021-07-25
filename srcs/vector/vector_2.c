#include "minirt.h"

t_vect	v_add(t_vect v, t_vect u)
{
	return (new_point((v.x + u.x), (v.y + u.y), (v.z + u.z)));
}

t_vect	v_sub(t_vect v, t_vect u)
{
	return (new_point((v.x - u.x), (v.y - u.y), (v.z - u.z)));
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
