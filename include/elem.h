#ifndef ELEM_H
# define ELEM_H


typedef struct	s_window		t_window;
typedef struct	s_image			t_image;
typedef struct	s_coord			t_coord;
typedef struct	s_background	t_background;
typedef struct	s_elem			t_elem;
typedef struct	s_scene			t_scene;

/*
**	--------------- BASIC TYPEDEFS ---------------
*/

typedef enum	e_type {
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}				t_type;

typedef struct	s_window
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	char	*title;
	int		save;
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
**	--------------- ELEMENTS STRUCTS ---------------
*/
typedef struct	s_scene
{
	t_background	background;
	t_elem			*elem;
}				t_scene;

typedef struct	s_background
{
	int		color;
}				t_background;

typedef struct	s_elem
{
	t_type			type;
	t_coord			center;
	int				side;
	int				color;
	struct s_elem	*next;
}				t_elem;



# endif
