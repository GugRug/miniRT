#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "minirt.h"
int main()
{

    //ft_validate(argc, argv); //validate_args and validate_file
    //need a struture with all args inside

	t_window	window;
	t_image		image;

	window.width = 1920;
	window.height = 1080;
	window.title = "ABACATE";
	window.mlx = mlx_init();
	window.ptr = mlx_new_window(window.mlx, window.width, window.height, window.title);
	mlx_loop(window.mlx);

	image.width = 1920;
	image.height = 1080;
	image.img = mlx_new_image(window.mlx, image.width, image.height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
    return (0);
}

