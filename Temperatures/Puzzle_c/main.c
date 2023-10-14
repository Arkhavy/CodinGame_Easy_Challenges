#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int	main(void)
{
	int	n;
	int	*temp;
	int	mem = 5527;
	int	k;
	int	val_print = 0;

	scanf("%d", &n);
	if (!n)
		return (printf("%d", n) * 0);
	else
	{
		temp = malloc(sizeof(int) * n);
		if (!temp)
			return (1);
		for (int i = 0; i < n; i++)
			scanf("%d", &temp[i]);
		for (int i = 0; i < n; i++)
		{
			k = 0;
			if (temp[i] < 0)
			{
				for (int j = temp[i]; j <= 0; j++)
					k++;
			}
			else if (temp[i] > 0)
			{
				for (int j = 0; j <= temp[i]; j++)
					k++;
			}
			else if (temp[i] == 0)
				return (printf("%d", temp[i]) * 0);
			if (k <= mem)
			{
				if (k == mem)
				{
					if (temp[i] > val_print)
						val_print = temp[i];
				}
				else
					val_print = temp[i];
				mem = k;
			}
		}
		printf("%d", val_print);
	}
	return (0);
}
