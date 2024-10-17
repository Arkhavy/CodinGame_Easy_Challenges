#include <iostream>
#include <string>
#include <vector>

#define MAP_WIDTH 40
#define MAP_HEIGHT 18

typedef	struct	s_coord	t_coord;

struct	s_coord
{
	int	x;
	int	y;
};

bool	isTargetOnLeft(t_coord const& origin, t_coord const& target)
{
	if (origin.x > target.x)
		return (true);
	return (false);
}

bool	isTargetOnRight(t_coord const& origin, t_coord const& target)
{
	if (origin.x < target.x)
		return (true);
	return (false);
}

bool	isTargetAbove(t_coord const& origin, t_coord const& target)
{
	if (origin.y > target.y)
		return (true);
	return (false);
}

bool	isTargetBelow(t_coord const& origin, t_coord const& target)
{
	if (origin.y < target.y)
		return (true);
	return (false);
}

int	main()
{
	t_coord	light;
	t_coord	thor;

	std::cin >> light.x >> light.y >> thor.x >> thor.y;
	std::cin.ignore();

	while (42)
	{
		int	remainingTurns;
		std::cin >> remainingTurns;
		std::cin.ignore();

		std::string	direction;
		t_coord	nextPosition;
		nextPosition.x = 0;
		nextPosition.y = 0;
		if (isTargetAbove(thor, light))
			nextPosition.y--;
		else if (isTargetBelow(thor, light))
			nextPosition.y++;
		if (isTargetOnLeft(thor, light))
			nextPosition.x--;
		else if (isTargetOnRight(thor, light))
			nextPosition.x++;

		if (nextPosition.y < 0) // goes up
			direction += "N";
		if (nextPosition.y > 0) // goes down
			direction += "S";
		if (nextPosition.x < 0) // goes left
			direction += "W";
		if (nextPosition.x > 0) // goes right
			direction += "E";
		std::cout << direction << std::endl;
		direction.clear();
		thor.x += nextPosition.x;
		thor.y += nextPosition.y;
	}
	return (0);
}