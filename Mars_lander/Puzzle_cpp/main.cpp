#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ZONE_WIDTH 7000
#define ZONE_HEIGHT 3000

#define GRAVITY 3.711

#define MIN_MAP_POINTS 2
#define MAX_MAP_POINTS 30

#define MIN_SPEED -500
#define MAX_SPEEED 500

#define MIN_LANDING_HSPEED -20
#define MAX_LANDING_HSPEED 20

#define MIN_LANDING_VSPEED -40
#define MAX_LANDING_VSPEED 40

#define MIN_FUEL 0
#define MAX_FUEL 2000

#define MIN_ROTATION_ANGLE -90
#define MAX_ROTATION_ANGLE 90

#define MIN_POWER 0
#define MAX_POWER 4

typedef	struct	s_map			t_map;
typedef	struct	s_coord		t_coord;
typedef	struct	s_shuttle	t_shuttle;

struct	s_coord
{
	int	x;
	int	y;
};

struct s_map
{
	int	surfaceN;
	std::vector<t_coord>	points;
};

struct	s_shuttle
{
	t_coord	pos;

	int	horizontalSpeed;
	int	verticalSpeed;

	int	fuel;
	int	rotationAngle;
	int	thrustPower;
};

int	main()
{
	t_map	map;
	std::cin >> map.surfaceN;
	std::cin.ignore();

	for (int i = 0; i < map.surfaceN; i++)
	{
		t_coord	tmpPoint;

		std::cin >> tmpPoint.x >> tmpPoint.y;
		std::cin.ignore();
		map.points.push_back(tmpPoint);
	}

	t_shuttle	shuttle;
	while (42)
	{
		std::cin >> shuttle.pos.x >> shuttle.pos.y;
		std::cin >> shuttle.horizontalSpeed >> shuttle.verticalSpeed;
		std::cin >> shuttle.fuel >> shuttle.rotationAngle >> shuttle.thrustPower;
		std::cin.ignore();

		if (shuttle.verticalSpeed <= MIN_LANDING_VSPEED && shuttle.thrustPower < 4)
			shuttle.thrustPower++;
		else if (shuttle.verticalSpeed > MIN_LANDING_VSPEED && shuttle.thrustPower > 0)
			shuttle.thrustPower--;
		std::cout << 0 << " " << shuttle.thrustPower << std::endl;
	}
}