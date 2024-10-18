#include <iostream>
#include <string>
#include <vector>

#define MAX_VECTOR_SIZE 1000000000

typedef	struct s_data	t_data;

struct	s_data
{
	int	quantity;
	int	value;
};

std::vector<t_data>	parseInput(std::string& str)
{
	std::vector<t_data>	tmpVector;
	for (std::size_t	i = 0; i < str.size(); i++)
	{
		t_data	tmpData;
		std::size_t	previousPos = i;
		tmpData.quantity = std::stoi(str, &i, 10);
		i++;
		str.replace(previousPos, i - previousPos, i - previousPos, ' ');
		previousPos = i;
		tmpData.value = std::stoi(str, &i, 10);
		str.replace(previousPos, i - previousPos, i - previousPos, ' ');
		tmpVector.push_back(tmpData);
	}
	return (tmpVector);
}

int	getSmallestQuantity(int itF, int itS)
{
	if (itF < itS)
		return (itF);
	return (itS);
}

int	main()
{
	std::string	firstLine;
	std::string	secondLine;
	std::getline(std::cin, firstLine);
	std::getline(std::cin, secondLine);

	std::vector<t_data>	firstVector = parseInput(firstLine);
	std::vector<t_data>	secondVector = parseInput(secondLine);

	std::vector<t_data>::iterator	itF = firstVector.begin();
	std::vector<t_data>::iterator	itS = secondVector.begin();
	long long int	dotProduct = 0;
	for (unsigned int operationCount = 0; operationCount < MAX_VECTOR_SIZE;) // will be incremented in batch
	{
		if (itF->quantity == 0)
			itF++;
		if (itS->quantity == 0)
			itS++;
		long long int	smallestQuantity = getSmallestQuantity(itF->quantity, itS->quantity);
		dotProduct += smallestQuantity * (itF->value * itS->value);
		itF->quantity -= smallestQuantity;
		itS->quantity -= smallestQuantity;
		operationCount += smallestQuantity;
	}
	std::cout << dotProduct << std::endl;
	return (0);
}