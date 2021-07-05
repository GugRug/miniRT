/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:34:16 by gumartin          #+#    #+#             */
/*   Updated: 2021/07/05 10:20:59 by gumartin         ###   ########.fr       */
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
# include "libft.h"
# include "mlx.h"
# include "elem.h"
# include "vector.h"

# define KEY_ESC	0xff1b
# define KEY_C		0x63

/*
**	--------------- FUNCTION DECLARATIONS ---------------
*/

//TESTE.c
int	write_test(void);
int	print_test(int p);
// int	render_next_frame(void *window);

/*
**	main.c
*/
void	set_window(t_window *window, t_image *image, t_rt *rt, t_scene *scene);

/*
**	color.c
*/
int		conv_color(int red, int green, int blue);
int		get_red(int rgb);
int		get_green(int rgb);
int		get_blue(int rgb);
int		add_shade(double shade, int rgb);

/*
**	draw.c
*/
void	draw_pixel(t_image *data, int x, int y, int color);
void	draw_background(t_image *img, int background);

/*
**	hook.c
*/
int		key_hook(int keycode, t_window *window);
int		destroy_window(t_window *window);

/*
**	elem.c
*/
void	draw_square(t_image *img, t_elem *sqr);
void	lst_elem_add_back(t_elem **lst, t_elem *new);
t_elem	*lst_elem_new(t_type type);
void	lst_elem_cut(t_elem *elem);
t_elem	*lst_elem_last(t_elem *lst);

/*
**	scene.c
*/
void	print_scene_elem(t_image *img, t_scene *scene);
void	select_scene_elem(t_image *img, t_elem *elem);

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

/*
**	validate.c
*/
void	validate_args(int argc, char **argv, t_rt *rt);
void	set_unique_elements(t_scene *scene, t_elem *elem);
bool	validate_rt_name(char *name);

/*
**	vector.c
*/
t_coord	build_point(long double x, long double y, long double z);
t_coord	v_add(t_coord v, t_coord u);
t_coord	v_sub(t_coord v, t_coord u);
t_coord	v_scale(t_coord v, double f);
t_coord	v_cross(t_coord v, t_coord u);
double	v_dot(t_coord v, t_coord u);
double	v_len(t_coord v);
double	v_len_sqr(t_coord v);

#endif
