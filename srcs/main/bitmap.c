#include "bitmap.h"

void	write_header(int fd, t_file_h header, t_bmp_h dib)
{
	write(fd, &header.type, 2);
	write(fd, &header.size, 4);
	write(fd, &header.reserved, 4);
	write(fd, &header.offset, 4);
	write(fd, &dib.size, 4);
	write(fd, &dib.width, 4);
	write(fd, &dib.height, 4);
	write(fd, &dib.colplanes, 2);
	write(fd, &dib.bpp, 2);
	write(fd, &dib.compression, 4);
	write(fd, &dib.img_size, 4);
	write(fd, &dib.x_ppm, 4);
	write(fd, &dib.y_ppm, 4);
	write(fd, &dib.color_number, 4);
	write(fd, &dib.important_color, 4);
}

static int	put_headers(int fd, unsigned int width, unsigned int height)
{
	t_file_h	fh;
	t_bmp_h		bh;

	fh.type[0] = 0x42;
	fh.type[1] = 0x4D;
	fh.size = 54 * width * height;
	fh.reserved = 0x00000000;
	fh.offset = 0x36;
	bh.size = 40;
	bh.width = width;
	bh.height = height;
	bh.colplanes = 1;
	bh.bpp = 32;
	bh.compression = 0;
	bh.img_size = 4 * width * height;
	bh.x_ppm = 2835;
	bh.y_ppm = 2835;
	bh.color_number = 0;
	bh.important_color = 0;
	write_header(fd, fh, bh);
	return (0);
}

int	export_bitmap(char *filename, int x, int y, t_image img)
{
	int		fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
	if (fd < 0 || (put_headers(fd, x, y)) < 0)
		return (-1);
	while (y-- > 0)
	{
		if ((write(fd, &img.addr[y * img.line_length], img.line_length)) < 0)
			return (-1);
	}
	if (close(fd) < 0)
		return (-1);
	return (0);
}
