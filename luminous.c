#include "luminous.h"

int	rgb_to_int(t_rgb rgb_color)
{
	int	color_out;

	color_out = 256 * 256 * rgb_color.red + 256 * rgb_color.green + rgb_color.blue;
	return (color_out);
}

t_rgb	add_rgb(t_rgb c1, t_rgb c2)
{
	t_rgb result;

	result.red = c1.red + c2.red;
	result.green = c1.green + c2.green;
	result.blue = c1.blue + c2.blue;
	return result;
}

t_rgb set_rgb(t_uchr red, t_uchr green, t_uchr blue)
{
	t_rgb color_out;
	color_out.red = red;
	color_out.green = green;
	color_out.blue = blue;
	return color_out;
}

void	print_rgb(t_rgb color)
{
	printf("R = %X | G = %X | B = %X\n", color.red, color.green, color.blue);
}

t_rgb	mix_colors(t_rgb color1, t_rgb color2, float ratio)
{
	t_rgb color_out;
	float ratio_c1;
	t_rgb color2_ratioed;

	if (1.0 <= ratio)
		return color2;
	else if (ratio <= 0)
		return color1;
	ratio_c1 = 1 - ratio;
	color_out = set_rgb(color1.red * ratio_c1, color1.green * ratio_c1, color1.blue * ratio_c1);
	color2_ratioed = set_rgb(color2.red * ratio, color2.green * ratio, color2.blue * ratio);
	color_out = add_rgb(color_out, color2_ratioed);
	return color_out;
}
