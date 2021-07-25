#ifndef ELEM_H
# define ELEM_H

# include <stdbool.h>
# include "basic_structs.h"
/*
**	--------------- ELEMENTS TYPEDEFS ---------------
*/
typedef struct s_res
{
	int			x;
	int			y;
	bool		declared;
}				t_res;

typedef struct s_amb_light
{
	double		amb_light;
	int			color;
	bool		declared;
}				t_amb_light;

typedef struct s_camera
{
	t_coord		orig;
	t_vect		normal;
	double		fov;
	t_vect		hor;
	t_vect		ver;
	t_coord		llc;
}				t_camera;

typedef struct s_light
{
	t_coord		l_p;
	double		brightness;
	int			color;
	bool		intersect;
}				t_light;

typedef struct s_sphere
{
	t_coord		center;
	double		diameter;
	int			color;
}				t_sphere;

typedef struct s_plane
{
	t_coord		point;
	t_vect		normal;
	int			color;
}				t_plane;

typedef struct s_square
{
	t_coord		center;
	t_vect		normal;
	t_vect		vertex[4];
	double		side;
	int			color;
}				t_square;

typedef struct s_cylinder
{
	t_coord		center;
	t_coord		normal;
	double		diameter;
	double		height;
	int			color;
}				t_cylinder;

typedef struct s_triangle
{
	t_vect		vertex[3];
	t_vect		normal;
	int			color;

}				t_triangle;

typedef struct s_elem
{
	t_type			type;
	t_res			res;
	t_amb_light		amb_light;
	t_camera		camera;
	t_light			light;
	t_sphere		sphere;
	t_plane			plane;
	t_square		square;
	t_cylinder		cylinder;
	t_triangle		triangle;
	struct s_elem	*next;
	struct s_elem	*prev;
}				t_elem;

# endif
