#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int	main(void)
{
	int	h_mem;
	int	i_mem;
	int	mountain_h;
	int	i;

	while (1)
	{
		h_mem = 0;
		i_mem = -1;
		i = 0;
		while (i < 8)
		{
			scanf("%d", &mountain_h);
			if (mountain_h >= h_mem)
			{
				h_mem = mountain_h;
				i_mem = i;
			}
			i++;
		}
		printf("%d\n", i_mem);
	}
	return (0);
}
