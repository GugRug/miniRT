#include "minirt.h"

int main(void)
{

    //ft_validate(argc, argv); //validate_args and validate_file
    //need a struture with all args inside

	t_window	window;
	t_image		image;
	int			color;

	window.width = 1920;
	window.height = 1080;
	window.title = "ABACATE";
	window.mlx = mlx_init();
	window.ptr = mlx_new_window(window.mlx, window.width, window.height, window.title);

	image.width = 1920;
	image.height = 1080;
	image.img = mlx_new_image(window.mlx, image.width, image.height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
	&image.line_length, &image.endian);

	color = conv_color(255, 255, 0);
	draw_test(&image, 50, 400, 400, color);
	printf("Inicial color: 0x%x\n", color);
	color = add_shade(0.5, color);
	draw_test(&image, 90, 700, 400, color);
	mlx_put_image_to_window(window.mlx, window.ptr, image.img, 0, 0);
	mlx_loop(window.mlx);
    return (0);
}
