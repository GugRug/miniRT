#ifndef BASIC_STRUCTS_H
# define BASIC_STRUCTS_H

typedef enum	e_type {
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

typedef enum	e_error{
	ERROR_CODE
}				t_error;

typedef struct	s_coord
{
	long double	x;
	long double	y;
	long double	z;
}				t_coord;

typedef	t_coord	t_vect;
typedef	int		t_color;

#endif