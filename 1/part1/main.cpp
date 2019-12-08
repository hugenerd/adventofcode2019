#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string inputLine;
	int totalFuel = 0;

	ifstream inputFile("input.dat");

	if (!inputFile)
	{
		cout << "Could not open input file!";
		return -1;
	}

	while (getline(inputFile, inputLine))
		totalFuel += (floor (stoi (inputLine) / 3) - 2);

	cout << "Total fuel: " << totalFuel << "\n";

	return 0;
}
