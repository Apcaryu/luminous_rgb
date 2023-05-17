#include "luminous.h"
#include "init.h"

int	render(t_data *data)
{
	char	*pix;
	int x;
	int y;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			pix = data->mlx_img.addr + (y * data->mlx_img.line_len + x * (data->mlx_img.bpp / 8));
			*(unsigned int *)pix = 0xFFFFFF;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->mlx_img.mlx_img, 0, 0);
	return 0;
}

int main(void)
{
	t_rgb base_color;
	t_rgb actual_color;

	base_color = set_rgb(255, 0, 0);
	actual_color = set_rgb(200, 255, 200);

	print_rgb(base_color);
	print_rgb(actual_color);
	mix_colors(base_color, actual_color, 0.5f);


	t_data data;

	init(&data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
	return 0;
}