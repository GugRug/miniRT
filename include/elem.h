#ifndef ELEM_H
# define ELEM_H

# include <stdbool.h>

/*
**	--------------- TYPEDEFS DECLARATIONS ---------------
*/

typedef enum	e_type			t_type;
typedef enum	e_error			t_error;
typedef struct	s_window		t_window;
typedef struct	s_image			t_image;
typedef struct	s_coord			t_coord;
typedef struct	s_rt			t_rt;
typedef struct	s_scene			t_scene;
typedef struct	s_elem			t_elem;
typedef struct	s_res			t_res;
typedef struct	s_amb_light		t_amb_light;
typedef struct	s_camera		t_camera;
typedef struct	s_light			t_light;
typedef struct	s_sphere		t_sphere;
typedef struct	s_plane			t_plane;
typedef struct	s_square		t_square;
typedef struct	s_cylinder		t_cylinder;
typedef struct	s_triangle		t_triangle;
typedef struct	s_canvas		s_canvas;

typedef 		t_coord 		t_vect;
/*
**	--------------- BASIC TYPEDEFS ---------------
*/

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


typedef struct	s_window
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	char	*title;
	t_rt	*rt;
}				t_window;

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct	s_coord
{
	long double	x;
	long double	y;
	long double	z;
}				t_coord;

/*
**	--------------- ARGS TYPEDEFS ---------------
*/

typedef struct	s_rt
{
	int			fd;
	bool		save;
	int			render_x;
	int			render_y;
	t_scene		*scene;
}				t_rt;

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

typedef struct	s_canvas
{
	int		width;
	int		height;
	int		**canv;
}				t_canvas;

typedef struct	s_scene
{
	t_elem		*elem;
	t_elem		*camera;
	t_elem		*light;
	t_canvas	canvas;
	t_res		res;
	t_amb_light	amb_light;
}				t_scene;

typedef struct	s_ray
{
	t_coord		orig;
	t_vect		dir;
}				t_ray;


# endif
