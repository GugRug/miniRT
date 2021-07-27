#ifndef BITMAP_H
# define BITMAP_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "minirt.h"

typedef struct s_file_h
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}					t_file_h;

typedef struct s_bmp_h
{
	unsigned int	size;
	int				width;
	int				height;
	unsigned short	colplanes;
	unsigned short	bpp;
	unsigned int	compression;
	unsigned int	img_size;
	int				x_ppm;
	int				y_ppm;
	unsigned int	color_number;
	unsigned int	important_color;
}					t_bmp_h;

#endif
