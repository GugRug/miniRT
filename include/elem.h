#ifndef ELEM_H
# define ELEM_H

# include <stdbool.h>

/*
**	--------------- TYPEDEFS DECLARATIONS ---------------
*/

typedef enum	e_type			t_type;
typedef struct	s_window		t_window;
typedef struct	s_image			t_image;
typedef struct	s_coord			t_coord;
typedef struct	s_rt			t_rt;
typedef struct	s_scene			t_scene;
typedef struct	s_elem			t_elem;

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
}				t_type;


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
	double	x;
	double	y;
	double	z;
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
typedef struct	s_scene
{
	t_elem		*elem;
	int			color_background;
}				t_scene;

typedef struct	s_elem
{
	t_type			*type;
	t_coord			*center;
	t_coord			*orient_vect;
	double			side;
	int				color;
	struct s_elem	*next;
}				t_elem;

# endif
