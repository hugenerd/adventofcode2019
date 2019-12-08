#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class intCode {
public:
	int loadProgram(string, int, int);
	void runProgram(void);

	vector<int> memory;
	int programOutput = 0;
};

int intCode::loadProgram(string inputFile, int noun, int verb)
{
	string subString;
	ifstream inputFilePtr(inputFile);

	if (!inputFilePtr)
		return -1;

	memory.clear();

	while (getline(inputFilePtr, subString, ','))
		memory.push_back (stoi(subString));

	memory[1] = noun;
	memory[2] = verb;

	return 1;
}

void intCode::runProgram()
{
	for (int i=0; i < (int) memory.size(); i++)
	{
		int opCode = memory[i];

		if (opCode == 99)
			break;

		int p1 = memory[i+1];
		int p2 = memory[i+2];
		int p3 = memory[i+3];

		if (opCode == 1)
			memory[p3] = memory[p1] + memory[p2];

		if (opCode == 2)
			memory[p3] = memory[p1] * memory[p2];

		i += 3;
	}

	programOutput = memory[0];

	return;
}

int main()
{
	intCode myProgram;

	for (int noun = 0; noun < 100; noun++)
	{
		for (int verb = 0; verb < 100; verb++)
		{
			if (!myProgram.loadProgram("input.dat", noun, verb))
			{
				cout << "Error loading program!\n";
				return -1;
			}

			myProgram.runProgram();

			if (myProgram.programOutput == 19690720)
			{
				cout << "noun: " << noun << "\n";
				cout << "verb: " << verb << "\n";
				cout << "answer: " << 100 * noun + verb << "\n";
				return 0;
			}
		}
	}

	return 0;
}
