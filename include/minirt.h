/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:34:16 by gumartin          #+#    #+#             */
/*   Updated: 2021/07/25 05:53:08 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include "libft.h"
# include "mlx.h"
# include "elem.h"
# include "canvas.h"
# include "validate_args.h"
# include "bitmap.h"

# define KEY_ESC	0xff1b
# define KEY_A		0x61
# define KEY_C		0x63
# define KEY_D		0x64
# define EPSILON	0.0001
# define FT_M_PI	3.14159265358979323846

/*
**	--------------- FUNCTION DECLARATIONS ---------------
*/

//TESTE.c
void	main_teste();
int		mouse_track(int button, int x, int y, t_window *window);
int		write_test(void);
int		print_test(double p);

/*
**	main.c
*/
void	set_init(t_window *window, t_rt *rt, t_scene *scene);
void	set_init_mlx(t_window *window, t_image *image);

/*
**	color.c
*/
int			clamp(int x);
t_color		color_conv(int red, int green, int blue);
t_color		color_add(t_color u, t_color v);
t_color		color_scale(t_color rgb, double c);
t_color		color_product(t_color u, t_color v);

/*
**	draw.c
*/
void	draw_pixel(t_image *data, int x, int y, int color);

/*
**	hook.c
*/
int		key_hook(int keycode, t_world *world);
int		destroy_window(t_window *window);
int		expose_hook(t_world *w);
int		call_hook(t_world *world);

/*
**	elem.c
*/
void	lst_elem_add_back(t_elem **lst, t_elem *new);
t_elem	*lst_elem_new(t_type type);
void	lst_elem_cut(t_elem *elem);
t_elem	*lst_elem_last(t_elem *lst);
void	lst_elem_clear(t_elem **lst);

/*
**	scene.c
*/
void	print_scene_elem(t_image *img, t_rt *rt);
void	select_scene_elem(t_scene *scene, t_elem *elem);

/*
**	rt_file.c
*/
void	set_rt(t_rt *rt);
void	distrib_elem(t_scene *scene, t_elem *elem);
t_elem	*set_rt_line_element(char *line);
void	set_rt_element_content(t_elem *elem, char **splitted);
void	clean_extra_space(char *line);

/*
**	rt_elem.c
*/
void	set_rt_resolution(t_elem *elem, char **splitted);
void	set_rt_ambient_lightining(t_elem *elem, char **splitted);
void	set_rt_camera(t_elem *elem, char **splitted);
void	set_rt_light(t_elem *elem, char **splitted);

/*
**	rt_elem_obj.c
*/
void	set_rt_sphere(t_elem *elem, char **splitted);
void	set_rt_plane(t_elem *elem, char **splitted);
void	set_rt_square(t_elem *elem, char **splitted);
void	set_rt_cylinder(t_elem *elem, char **splitted);
void	set_rt_triangle(t_elem *elem, char **splitted);

/*
**	rt_elem_utils.c
*/
double	ft_atof(const char *str);
t_coord	set_rt_point(char *str);
int		set_rt_color(char *str);
void	set_square_vertex(t_square *s);

/*
**	validate.c
*/
void	validate_args(int argc, char **argv, t_rt *rt);
void	set_unique_elements(t_scene *scene, t_elem *elem);
bool	validate_rt_name(char *name);

/*
**	vector.c
*/
t_coord	new_point(double x, double y, double z);
t_vect	v_scale(t_vect v, double f);
double	v_len(t_vect v);
double	v_len_sqred(t_vect v);
t_vect	v_norm(t_vect v);

/*
**	vector_2.c
*/
t_vect	v_position(t_vect v, t_vect u, double t);
t_vect	v_add(t_vect v, t_vect u);
t_vect	v_sub(t_vect v, t_vect u);
t_vect	v_cross(t_vect v, t_vect u);
double	v_dot(t_vect v, t_vect u);

/*
**	canvas.c
*/
t_canvas	new_canvas(int width, int height);
void		set_canvas_point(t_canvas *canvas, int x, int y, int color);
void		print_canvas(t_canvas *canvas, t_image *img);
void		set_canvas(t_canvas *canvas, t_scene *scene);

/*
**	ray.c
*/
t_ray	new_ray(t_coord orig, t_vect dir);
double	bhaskara(double a, double b, double c, double *root);
void	ray_position(t_ray *ray);

/*
**	raytrace.c
*/
t_color	raytrace(t_ray *ray, t_scene *scene);
bool	light_intersect(t_ray *ray, t_light *light, t_scene *scene, t_color *color);
void	intersect(t_ray *ray, t_scene *scene);
t_ray	start_raytrace(t_scene *scene, double u, double v);

/*
**	hit.c
*/
bool	hit_sphere(t_elem *elem,t_ray *ray);
bool	hit_plane(t_elem *elem,t_ray *ray);
bool	hit_square(t_elem *elem,t_ray *ray);
bool	hit_cylinder(t_elem *elem,t_ray *ray);
bool	hit_triangle(t_elem *elem,t_ray *ray);

/*
**	hit_utils.c
*/
bool	hit_sphere_root(t_elem *elem, t_ray *ray, double *root);;
bool	is_inside(t_ray r, t_coord *v, unsigned int vertex);
double	cy_calc(t_ray ray, t_elem cy, double *y, bool ret[2]);

/*
**	camera.c
*/
void	init_camera(t_camera *camera, t_scene *scene);
void	change_camera(int keycode, t_world *w);

/*
**	error.c
*/
void	message_and_exit(t_error code, char *str);

/*
**	validate_utils.c
*/
int		strarray_len(char **str);
bool	validate_unit_range(double a, double b, double c);
bool	validate_posit(double a, double b, double c);
bool	valid_float(const char *str);
bool	valid_int(const char *str);

/*
**	clean.c
*/
void	free_array(char **array);
int		free_all(t_world *w);

/*
** bitmap.c
*/
int			export_bitmap(char *filename, int width,
							int height, t_image img);

#endif
