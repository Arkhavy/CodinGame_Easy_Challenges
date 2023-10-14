#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int	main(void)
{
	int	light_x;
	int	light_y;
	int	initial_tx;
	int	initial_ty;
	int	remaining_turns;
	int	tx;
	int	ty;

	scanf("%d%d%d%d", &light_x, &light_y, &initial_tx, &initial_ty);
	tx = initial_tx;
	ty = initial_ty;
	dprintf(2, "start x %d y %d lx %d ly %d\n", initial_tx, initial_ty, light_x, light_y);
	while (42)
	{
		scanf("%d", &remaining_turns);
		dprintf(2, "x %d y %d t %d\n", tx, ty, remaining_turns);
		if (light_x > tx)
		{
			if (light_y > ty)
			{
				printf("SE\n");
				tx++;
				ty++;
			}
			else if (light_y == ty)
			{
				printf("E\n");
				tx++;
			}
			else
			{
				printf("NE\n");
				tx++;
				ty--;
			}
		}
		else if (light_x == tx)
		{
			if (light_y > ty)
			{
				printf("S\n");
				ty++;
			}
			else
			{
				printf("N\n");
				ty--;
			}
		}
		else
		{
			if (light_y > ty)
			{
				printf("SW\n");
				tx--;
				ty++;
			}
			else if (light_y == ty)
			{
				printf("W\n");
				tx--;
			}
			else
			{
				printf("NW\n");
				tx--;
				ty--;
			}
		}
	}
	return (0);
}
