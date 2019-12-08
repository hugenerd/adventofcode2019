#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string subString;
	vector<int> intCode;

	ifstream inputFile("input.dat");

	if (!inputFile)
	{
		cout << "Could not open input file!";
		return -1;
	}

	while (getline(inputFile, subString, ','))
		intCode.push_back (stoi(subString));

	intCode[1] = 12;
	intCode[2] = 2;

	for (int i=0; i < (int) intCode.size(); i++)
	{
		if (intCode[i] == 99)
			break;

		if (intCode[i] == 1)
			intCode[intCode[i+3]] = 
				intCode[intCode[i+1]] + intCode[intCode[i+2]];

		if (intCode[i] == 2)
			intCode[intCode[i+3]] = 
				intCode[intCode[i+1]] * intCode[intCode[i+2]];

		i += 3;
	}

	cout << "Position 0: " << intCode[0] << "\n";

	return 0;
}
