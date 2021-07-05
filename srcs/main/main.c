#include "minirt.h"

int main(int argc, char **argv)
{
	t_window	window;
	t_image		image;
	t_rt		rt;
	t_scene		scene;


	window.rt = &rt;
	window.rt->scene = &scene;
	window.rt->scene->elem = NULL;
	window.rt->scene->camera = NULL;
	window.rt->scene->light = NULL;
	window.rt->scene->res.declared = false;
	window.rt->scene->amb_light.declared = false;
	validate_args(argc, argv, window.rt);
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


	print_scene_elem(&image, window.rt->scene);


	mlx_put_image_to_window(window.mlx, window.win, image.img, 0, 0);
	mlx_hook(window.win, 4, 1L << 2, print_test, &window);
	mlx_hook(window.win, 33, 1L << 17, destroy_window, &window);
	mlx_key_hook(window.win, key_hook, &window);
	//mlx_loop_hook(window.mlx, render_next_frame, &window);
	mlx_loop(window.mlx);
	return (0);
}

// int main() {

//     // Image

//     const int image_width = 256;
//     const int image_height = 256;

//     // Render

//     // std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
// 	printf("P3\n%d %d\n255\n", image_width, image_height);

//     for (int j = image_height-1; j >= 0; --j) {
//         for (int i = 0; i < image_width; ++i) {
//             double r = (double)i / (image_width-1);
//             double g = (double)j / (image_height-1);
//             double b = 0.25;

//             int ir = (int)(255.999 * r);
//             int ig = (int)(255.999 * g);
//             int ib = (int)(255.999 * b);

//             // std::cout << ir << ' ' << ig << ' ' << ib << '\n';
// 			printf("%d %d %d\n", ir, ig, ib);
//         }
//     }
// }
