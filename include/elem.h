#ifndef ELEM_H
# define ELEM_H

# include <stdbool.h>
# include "basic_structs.h"
/*
**	--------------- ELEMENTS TYPEDEFS ---------------
*/
typedef struct	s_res
{
	int			x;
	int			y;
	bool		declared;
}				t_res;

typedef struct	s_amb_light
{
	double		amb_light;
	int			color;
	bool		declared;
}				t_amb_light;

typedef struct	s_camera
{
	t_coord		v_p;
	t_vect		orient_vect;
	int			fov;
}				t_camera;

typedef struct	s_light
{
	t_coord		l_p;
	double		brightness;
	int			color;
}				t_light;

typedef struct	s_sphere
{
	t_coord		center;
	double		diameter;
	int			color;
}				t_sphere;

typedef struct	s_plane
{
	t_coord		f_p;
	t_coord		orient_vect;
	int			color;
}				t_plane;

typedef struct	s_square
{
	t_coord		center;
	t_coord		orient_vect;
	double		side;
	int			color;
}				t_square;

typedef struct	s_cylinder
{
	t_coord		center;
	t_coord		orient_vect;
	double		diameter;
	double		height;
	int			color;
}				t_cylinder;

typedef struct	s_triangle
{
	t_coord		f_p;
	t_coord		s_p;
	t_coord		t_p;
	int			color;

}				t_triangle;

typedef struct	s_elem
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
