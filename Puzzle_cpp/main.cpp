#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	while (1)
	{
		int	index_memory = -1;
		int	height_memory = 0;
		int	mountain_height = 0;
		for (int i = 0; i < 8; i++)
		{
			cin >> mountain_height; cin.ignore();
			cerr << mountain_height << endl;
			cerr << height_memory << endl;
			cerr << i << " i vs index " << index_memory << endl;
			if (mountain_height >= height_memory || i == -1)
			{
				height_memory = mountain_height;
				index_memory = i;
			}
		}
		cout << index_memory << endl;
	}
}
