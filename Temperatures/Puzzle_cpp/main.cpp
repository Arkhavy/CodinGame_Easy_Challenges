#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define FARTHEST_TEMPERATURE 5527

int	main()
{
	int	TemperatureNumber;
	std::cin >> TemperatureNumber;
	std::cin.ignore();

	int	closestTemperature = FARTHEST_TEMPERATURE;
	for (int i = 0; i < TemperatureNumber; i++)
	{
		int	tmpTemperature;
		std::cin >> tmpTemperature;
		std::cin.ignore();
		if (abs(tmpTemperature) == abs(closestTemperature))
		{
			if (tmpTemperature > closestTemperature)
				closestTemperature = tmpTemperature;
		}
		else if (abs(tmpTemperature) < abs(closestTemperature))
			closestTemperature = tmpTemperature;
	}
	if (closestTemperature == FARTHEST_TEMPERATURE)
		closestTemperature = 0;
	std::cout << closestTemperature << std::endl;
	return (0);
}