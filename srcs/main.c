#include "minirt.h"

int main(int argc, char **argv)
{

    //ft_validate(argc, argv); //validate_args and validate_file
    //need a struture with all args inside





	t_window	window;
	t_image		image;
	// t_scene		scene;

	window.width = 1920;
	window.height = 1080;
	window.title = "ABACATE";
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width, window.height, window.title);

	image.width = 1920;
	image.height = 1080;
	image.img = mlx_new_image(window.mlx, image.width, image.height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
	&image.line_length, &image.endian);

	// color = conv_color(255, 255, 0);
	// draw_square(&image, 50, 400, 400, color);
	// color = add_shade(0.5, color);
	// draw_square(&image, 90, 700, 400, color);
	validate_args(argc, argv, window.rt);
	// get_scene_elem(&scene);
	print_scene_elem(&image, &window.rt->scene);

	mlx_put_image_to_window(window.mlx, window.win, image.img, 0, 0);

	mlx_hook(window.win, 4, 1L << 2, print_test, &window);
	mlx_hook(window.win, 33, 1L << 17, destroy_window, &window);
	mlx_key_hook(window.win, key_hook, &window);
	//mlx_loop_hook(window.mlx, render_next_frame, &window);
	mlx_loop(window.mlx);
	return (0);
}
