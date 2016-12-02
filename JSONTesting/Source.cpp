#include <iostream>
#include <map>
#include "json.hpp"
#include <fstream>


// for convenience
using json = nlohmann::json;
using namespace std;

enum frameType { dialogue = 0, centeredText, fullScreenNarriation };
struct storyElement
{
	int index;
	frameType outputType = (frameType)0;
	std::string speaker;
	std::string dialogue;
};

int main()
{
	ifstream fin;
	ofstream fout;
	json j;

	fin.open("ardonianEmbassy.json", ifstream::binary);

	if (!fin)
	{
		cout << "Bad shit happened, exiting" << endl;
		return 22;
	}

	fin >> j;

	cout << j;

	return 0;

}
