#ifndef BASIC_STRUCTS_H
# define BASIC_STRUCTS_H

typedef enum e_type {
	RESOLUTION,
	AMBIENT_LIGHTINING,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}				t_type;

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}				t_coord;

typedef t_coord	t_vect;
typedef int		t_color;

#endif
