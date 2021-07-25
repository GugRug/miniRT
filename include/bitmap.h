#ifndef BITMAP_H
# define BITMAP_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "minirt.h"

# define BM					0x4D42
# define HEADER_SIZE		54
# define FILE_HEADER_SIZE	14
# define BMP_HEADER_SIZE	40
# define BI_RGB				0

# pragma pack(push, 1)

typedef struct		s_file_h
{
	short int		type;
	int				size;
	int				reserved;
	unsigned int	offset;
}					t_file_h;

typedef struct		s_bmp_h
{
	unsigned int	size;
	int				width;
	int				height;
	short int		planes;
	short int		bpp;
	unsigned int	compression;
	unsigned int	image_size;
	int				ppm_x;
	int				ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bmp_h;

# pragma pack(pop)

#endif
