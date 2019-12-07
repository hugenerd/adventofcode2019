#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string inputLine;
	int moduleFuel = 0;
	int totalFuel = 0;

	ifstream inputFile ("input.dat");

	if (!inputFile)
	{
		cout << "Could not open input file!";
		return -1;
	}

	while (getline (inputFile, inputLine))
	{
		moduleFuel = (floor (stoi (inputLine) / 3) - 2);
		int moreFuel = moduleFuel;

		while (moreFuel > 0)
		{
			int tmpFuel = floor (moreFuel / 3) - 2;
			moreFuel = tmpFuel;
			if (tmpFuel > 0)
				moduleFuel += tmpFuel;
		}

		totalFuel += moduleFuel;
	}

	cout << "Total fuel: " << totalFuel << "\n";

	return 0;
}
