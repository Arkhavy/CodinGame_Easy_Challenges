#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 7000
#define HEIGHT 3000
#define GRAVITY 3.711

typedef struct s_data	t_data;

struct s_data
{
	int	surface_n; // the number of points used to draw the surface of Mars.
	int	*land_x; // X coordinate of a surface point. (0 to 6999)
	int	*land_y; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
	int	x; // x position
	int	y; // y position
	int	h_speed; // the horizontal speed (in m/s), can be negative.
	int	v_speed; // the vertical speed (in m/s), can be negative.
	int	fuel; // the quantity of remaining fuel in liters.
	int	rotate; // the rotation angle in degrees (-90 to 90).
	int	power; // the thrust power (0 to 4).
};

int	main(void)
{
	t_data	data;
	int	surface_n;
	int	land_x;
	int	land_y;

	scanf("%d", &surface_n);
	data.land_x = malloc(sizeof(int) * surface_n);
	data.land_y = malloc(sizeof(int) * surface_n);
	for (int i = 0; i < surface_n; i++)
		scanf("%d%d", &data.land_x[i], &data.land_y[i]);
	while (42)
	{
		scanf("%d%d", &data.x, &data.y);
		scanf("%d%d", &data.h_speed, &data.v_speed);
		scanf("%d%d%d", &data.fuel, &data.rotate, &data.power);
		if (data.v_speed < -30)
			printf("0 4\n");
		else // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
			printf("0 0\n");
	}
	free (data.land_x);
	free (data.land_y);
	return (0);
}

