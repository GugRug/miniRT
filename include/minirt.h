/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:34:16 by gumartin          #+#    #+#             */
/*   Updated: 2021/06/08 21:01:08 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

/*
**	--------------- BASIC STRUCTS ---------------
*/

typedef struct	s_window
{
	void	*mlx;
	void	*ptr;
	int		height;
	int		width;
	char	*title;
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
	double		x;
	double		y;
	double		z;
}				t_coord;

/*
**	--------------- FUNCTION DECLARATIONS ---------------
*/

//TESTE.c
void	draw_test(t_image *img, int side, int cen_x, int cen_y, int color);

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

#endif
