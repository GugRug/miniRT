#ifndef CANVAS_H
# define CANVAS_H

# include <stdbool.h>
# include "basic_structs.h"
# include "elem.h"

/*
**	--------------- BASIC TYPEDEFS ---------------
*/

typedef	struct s_rt		t_rt;
typedef	struct s_scene	t_scene;
typedef	struct s_ray	t_ray;

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

/*
**	--------------- ARGS TYPEDEFS ---------------
*/

typedef struct	s_rt
{
	int			fd;
	bool		save;
	int			width;
	int			height;
	t_scene		*scene;
}				t_rt;

typedef struct	s_canvas
{
	int		width;
	int		height;
	int		**canv;
}				t_canvas;


typedef struct	s_ray
{
	t_coord		orig;
	t_vect		dir;
	t_vect		pos;
	t_vect		norm;
	t_vect		normal;
	double		*root;
	double		t;
	bool		intersect;
	int			color;
}				t_ray;

typedef struct	s_scene
{
	t_elem		*elem;
	t_elem		*camera;
	t_elem		*light;
	t_canvas	canvas;
	t_ray		ray;
	t_res		res;
	t_amb_light	amb_light;
}				t_scene;

#endif
