#include "luminous.h"

int main(void)
{
	t_rgb base_color;
	t_rgb actual_color;

	base_color = set_rgb(255, 0, 0);
	actual_color = set_rgb(200, 255, 200);

	print_rgb(base_color);
	print_rgb(actual_color);
	mix_colors(base_color, actual_color, 0.5f);
	return 0;
}