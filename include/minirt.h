/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:34:16 by gumartin          #+#    #+#             */
/*   Updated: 2021/06/13 22:10:55 by gumartin         ###   ########.fr       */
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

# define KEY_ESC	0xff1b
# define KEY_C		0x63

/*
**	--------------- FUNCTION DECLARATIONS ---------------
*/

//TESTE.c
int	print_test(void);
// int	render_next_frame(void *window);

/*
**	color.c
*/
int	conv_color(int red, int green, int blue);
int	get_red(int rgb);
int	get_green(int rgb);
int	get_blue(int rgb);
int	add_shade(double shade, int rgb);

/*
**	draw.c
*/
void	draw_pixel(t_image *data, int x, int y, int color);
void	draw_background(t_image *img, t_background background);

/*
**	hook.c
*/
int		key_hook(int keycode, t_window *window);
int		destroy_window(t_window *window);

/*
**	elem.c
*/
void	draw_square(t_image *img, t_elem sqr);
void	lst_elem_add_back(t_elem **lst, t_elem *new);
t_elem	*lst_elem_last(t_elem *lst);
t_elem	*lst_elem_new(t_type type);

/*
**	scene.c
*/
void	get_scene_elem(t_scene *scene);
void	print_scene_elem(t_image *img, t_scene *scene);

#endif
