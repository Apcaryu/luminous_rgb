#include "init.h"

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, WIN_X, WIN_Y, "luminous");
	data->mlx_img.mlx_img = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	data->mlx_img.addr = mlx_get_data_addr(data->mlx_img.mlx_img, \
	&data->mlx_img.bpp, &data->mlx_img.line_len, &data->mlx_img.endian);
}