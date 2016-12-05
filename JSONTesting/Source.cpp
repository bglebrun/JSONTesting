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
	json k;
	string storyTitle;
	vector <int> storykeys;
	vector <json> stories;
	int temp;

	fin.open("ardonianEmbassy.json", ifstream::binary);

	if (!fin)
	{
		cout << "Bad shit happened, exiting" << endl;
		return 22;
	}

	fin >> j;

	storyTitle = j["story"];

	k = j["content"];

	cout << storyTitle << endl << endl;


	for (auto i : k) {
		//cout << i << endl << endl;
		temp = i["storyKey"];
		storykeys.push_back(temp);
	}

	cout << "Story keys loaded in order: " << endl;

	for (auto i : storykeys)
	{
		cout << i << endl;
	}

/*	for (json::iterator it = j.begin(); it != j.end(); ++it) {
		std::cout << it.key() << " : " << it.value() << "\n";
	}*/

	for (auto i : k)
	{
		stories.push_back(i["story"]);
	}

	for (auto i : stories)
	{
		for (auto p : i) {
			if (p["speaker"] != "")
				cout << endl << p["speaker"] << ": " << endl;

			cout << endl << p["text"] << endl << endl;
			system("PAUSE");
		}
	}

	return 0;

}
