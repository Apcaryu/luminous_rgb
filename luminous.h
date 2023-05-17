#ifndef	LUMINOUS_H
# define LUMINOUS_H
# include <stdio.h>

typedef unsigned char t_uchr;

typedef struct s_rgb
{
	t_uchr red;
	t_uchr green;
	t_uchr blue;
} t_rgb;

int	rgb_to_int(t_rgb rgb_color);

t_rgb	add_rgb(t_rgb c1, t_rgb c2);

t_rgb set_rgb(t_uchr red, t_uchr green, t_uchr blue);

void	print_rgb(t_rgb color);

t_rgb	mix_colors(t_rgb color1, t_rgb color2, float ratio);

#endif