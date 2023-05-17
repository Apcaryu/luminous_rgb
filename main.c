#include "luminous.h"
#include "init.h"

int	*color_tab(int win_size_x, t_rgb a_color, t_rgb b_color)
{
	int *tab = malloc(sizeof(int) * WIN_X);
	int x = 0;

	while (x < win_size_x)
	{
		tab[x] = rgb_to_int(mix_colors(a_color, b_color, (1.0f / WIN_X) * (float)x));
		x++;
	}
	return tab;
}

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
			*(unsigned int *)pix = data->color_tab[x];
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
	data.color_tab = color_tab(WIN_X, base_color, actual_color);
	mlx_loop(data.mlx);
	return 0;
}