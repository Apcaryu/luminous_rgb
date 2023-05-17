#ifndef INIT_H
# define INIT_H
# define WIN_X 1000
# define WIN_Y 1000
//# include <X11/keysym.h>
//# include <X11/X.h>
//# include <fcntl.h>
//# include <math.h>
# include "minilibx-linux/mlx.h"
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_window;
	t_img	mlx_img;
}t_data;

void	init(t_data *data);

#endif