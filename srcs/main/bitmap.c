#include "bitmap.h"

static int	put_headers(int fd, unsigned int width, unsigned int height)
{
	t_file_h	fh;
	t_bmp_h		bh;

	fh.type = BM;
	fh.size = HEADER_SIZE + 4 * width * height;
	fh.reserved = 0;
	fh.offset = HEADER_SIZE;
	bh.size = BMP_HEADER_SIZE;
	bh.width = width;
	bh.height = height;
	bh.planes = 1;
	bh.bpp = 32;
	bh.compression = BI_RGB;
	bh.image_size = 4 * width * height;
	bh.ppm_x = 2000;
	bh.ppm_y = 2000;
	bh.clr_used = 0;
	bh.clr_important = 0;
	if ((write(fd, (void *)&fh, FILE_HEADER_SIZE) < 0)
		|| (write(fd, (void *)&bh, BMP_HEADER_SIZE) < 0))
		return (-1);
	return (0);
}

int			export_bitmap(char *filename, int width, int height, t_image img)
{
	int		fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
	if (fd < 0 || (put_headers(fd, width, height)) < 0)
		return (-1);
	while (height-- > 0)
	{
		if ((write(fd, &img.addr[height * img.line_length], img.line_length)) < 0)
			return (-1);
	}
	if (close(fd) < 0)
		return (-1);
	return (0);
}
