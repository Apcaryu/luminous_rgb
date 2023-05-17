#include "luminous.h"

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
	color_out = set_rgb(0, 0, 0);
	printf("ratio1 = %f\n", ratio_c1);
	color_out = set_rgb(color1.red * ratio_c1, color1.green * ratio_c1, color1.blue * ratio_c1);
	print_rgb(color_out);
	color2_ratioed = set_rgb(color2.red * ratio, color2.green * ratio, color2.blue * ratio);
	print_rgb(color2_ratioed);
	color_out = add_rgb(color_out, color2_ratioed);
	print_rgb(color_out);
	return color_out;
}
