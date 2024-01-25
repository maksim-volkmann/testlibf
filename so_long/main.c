
#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include "so_long.h"

#define WIDTH 384
#define HEIGHT 384

mlx_image_t	*g_img;

void	hook(void *param)
{

	t_my_data	*data;
	mlx_t		*mlx;

	data = (t_my_data *)param;
	mlx = data->mlx;
	// static int	i = 0;


	//mlx = param;
	// data->i++;
	// printf("THIS IS HOOOOK %d\n", (data->i++));
	// printf("This is hook, but for b %d\n", data->c--);


if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if ((mlx_is_key_down(mlx, MLX_KEY_UP)) | (mlx_is_key_down(mlx, MLX_KEY_W))) {
		g_img->instances[0].y -= 5;
		// printf("Position - X: %d, Y: %d\n", g_img->instances[0].x, g_img->instances[0].y);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) | (mlx_is_key_down(mlx, MLX_KEY_S))) {
		g_img->instances[0].y += 5;
		// printf("Position - X: %d, Y: %d\n", g_img->instances[0].x, g_img->instances[0].y);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) | (mlx_is_key_down(mlx, MLX_KEY_A))) {
		g_img->instances[0].x -= 5;
		// printf("Position - X: %d, Y: %d\n", g_img->instances[0].x, g_img->instances[0].y);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) | (mlx_is_key_down(mlx, MLX_KEY_D))) {
		g_img->instances[0].x += 5;
		// printf("Position - X: %d, Y: %d\n", g_img->instances[0].x, g_img->instances[0].y);
	}
}

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(int argc, char **argv)
{
	mlx_t	*mlx;
	int		fd;
	int		c_count;
	ssize_t	read_bytes;
	char	buffer[BUFFER_SIZE + 1];

	// buffer[BUFFER_SIZE] = '\0';
	fd = open("map1.ber", O_RDONLY);
	read_bytes = read(fd, buffer, BUFFER_SIZE);

	printf("Buffer:\n");
	printf("%s\n", buffer);
	while(read_bytes > 0)
	{
		if(read_bytes == 0)
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		printf("Buffer:\n");
		printf("%s\n", buffer);

	}

	printf("bytes: %zd\n", read_bytes);
	printf("Buffer:\n");
	printf("%s\n", buffer);
	printf("Main Function\n");
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 50, 50);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));

	mlx_texture_t* texture = mlx_load_png("tile.png");
	if (!texture)
		error();

	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();

	// Display the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();
	if (mlx_image_to_window(mlx, img, 0, 128) < 0)
		error();
	if (mlx_image_to_window(mlx, img, 0, 256) < 0)
		error();
	if (mlx_image_to_window(mlx, img, 0, 384) < 0)
		error();
	if (mlx_image_to_window(mlx, img, 128, 0) < 0)
		error();
	if (mlx_image_to_window(mlx, img, 128, 128) < 0)
		error();
	if (mlx_image_to_window(mlx, img, 128, 256) < 0)
		error();
	if (mlx_image_to_window(mlx, img, 128, 384) < 0)
		error();
	if (mlx_image_to_window(mlx, img, 256, 0) < 0)
		error();
	if (mlx_image_to_window(mlx, img, 256, 128) < 0)
		error();
	if (mlx_image_to_window(mlx, img, 256, 256) < 0)
		error();
	if (mlx_image_to_window(mlx, img, 256, 384) < 0)
		error();

	t_my_data	data;
	t_mynumber	anyVarNameIWant;

	anyVarNameIWant.b = 8;
	data.i = 0;
	data.mlx = mlx;
	data.c = anyVarNameIWant.b;
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, &data);

	// mlx_loop_hook(mlx, &hook2, &data);
	// data.i = 0;
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// cc -W -W -W main.c MLX42/build/libmlx42.a -Iinclude -lglfw && ./a.out

// #include "MLX42/include/MLX42/MLX42.h"
// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <memory.h>
// #include <errno.h>
// #include <fcntl.h>
// #include <stdbool.h>
// #include "so_long.h"

// #define WIDTH 384
// #define HEIGHT 384

// mlx_image_t	*g_img;

// typedef struct s_my_data
// {
// 	mlx_t	*mlx;
// 	int		i;
// } t_my_data;


// void	hook(void *param)
// {

// 	t_my_data	*data;

// 	data = (t_my_data *)param;
// 	mlx_t	*mlx;

// 	mlx = data->mlx;
// 	// static int	i = 0;


// 	data->i = 0;
// 	mlx = param;
// 	(data->i)++;
// 	printf("THIS IS HOOOOK %d\n", (data->i));


// if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if ((mlx_is_key_down(mlx, MLX_KEY_UP)) | (mlx_is_key_down(mlx, MLX_KEY_W))) {
// 		g_img->instances[0].y -= 5;
// 		printf("Position - X: %d, Y: %d\n", g_img->instances[0].x, g_img->instances[0].y);
// 	}
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) | (mlx_is_key_down(mlx, MLX_KEY_S))) {
// 		g_img->instances[0].y += 5;
// 		printf("Position - X: %d, Y: %d\n", g_img->instances[0].x, g_img->instances[0].y);
// 	}
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) | (mlx_is_key_down(mlx, MLX_KEY_A))) {
// 		g_img->instances[0].x -= 5;
// 		printf("Position - X: %d, Y: %d\n", g_img->instances[0].x, g_img->instances[0].y);
// 	}
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) | (mlx_is_key_down(mlx, MLX_KEY_D))) {
// 		g_img->instances[0].x += 5;
// 		printf("Position - X: %d, Y: %d\n", g_img->instances[0].x, g_img->instances[0].y);
// 	}
// }

// static void error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// int32_t	main(int argc, char **argv)
// {
// 	mlx_t	*mlx;
// 	int		fd;
// 	int		c_count;
// 	ssize_t	read_bytes;
// 	char	buffer[BUFFER_SIZE + 1];

// 	// buffer[BUFFER_SIZE] = '\0';
// 	fd = open("map1.ber", O_RDONLY);
// 	read_bytes = read(fd, buffer, BUFFER_SIZE);
// 	printf("bytes: %zd\n", read_bytes);
// 	printf("Main Function\n");
// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);
// 	g_img = mlx_new_image(mlx, 50, 50);
// 	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));

// 	mlx_texture_t* texture = mlx_load_png("tile.png");
// 	if (!texture)
// 		error();

// 	// Convert texture to a displayable image
// 	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
// 	if (!img)
//         error();

// 	// Display the image
// 	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
//         error();
// 	if (mlx_image_to_window(mlx, img, 0, 128) < 0)
//         error();
// 	if (mlx_image_to_window(mlx, img, 0, 256) < 0)
//         error();
// 	if (mlx_image_to_window(mlx, img, 0, 384) < 0)
//         error();
// 	if (mlx_image_to_window(mlx, img, 128, 0) < 0)
//         error();
// 	if (mlx_image_to_window(mlx, img, 128, 128) < 0)
//         error();
// 	if (mlx_image_to_window(mlx, img, 128, 256) < 0)
//         error();
// 	if (mlx_image_to_window(mlx, img, 128, 384) < 0)
//         error();
// 	if (mlx_image_to_window(mlx, img, 256, 0) < 0)
//         error();
// 	if (mlx_image_to_window(mlx, img, 256, 128) < 0)
//         error();
// 	if (mlx_image_to_window(mlx, img, 256, 256) < 0)
//         error();
// 	if (mlx_image_to_window(mlx, img, 256, 384) < 0)
//         error();

// 	//t_my_data	data;

// 	mlx_image_to_window(mlx, g_img, 0, 0);
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

// // cc -W -W -W main.c MLX42/build/libmlx42.a -Iinclude -lglfw && ./a.out
