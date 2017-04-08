#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>

using namespace std;



void periodic(string input, map<string,string> data)
{
	queue <string> chars;
	queue <string> elements;

	for (int i = 0; i < input.size(); i++)
	{
		char tempc = input[i];
		string tempstr;
		tempstr.push_back(toupper(tempc));
		map<string, string>::iterator temp = data.find( tempstr);
		if (temp != data.end())
		{
			chars.push(temp->first);
			elements.push(temp->second);
		}
		else
		{
			i++;
			tempc = input[i];
			tempstr.push_back(tolower(tempc));
			temp = data.find(tempstr);
			if (temp != data.end())
			{
				chars.push(temp->first);
				elements.push(temp->second);
			}
			else
			{
				chars.pop(); elements.pop();
				tempstr = "";
				tempstr.push_back(toupper(input[i - 2]));
				tempstr.push_back(tolower(input[i - 1]));

				i--;
				temp = data.find(tempstr);
				chars.push(temp->first);
				elements.push(temp->second);
			}
			
		}
	}

	while (chars.empty() != true)
	{
		cout << chars.front();
		chars.pop();
	}

	cout << "  (";
	while (elements.empty() != true)
	{
		cout << elements.front() << ", ";
		elements.pop();
	}
	cout << ")" << endl;
}

int main()
{
	ifstream inFile;
	inFile.open("periodic.txt");
	string str1, str2, garbage;
	map<string, string> data;

	while (inFile >> str1 >> str2)
		data.insert(pair<string, string>(str2, str1));
	for (pair<string, string> p : data)
		cout << p.first << " " << p.second << endl;
	string input;
	while (input != "0")
	{
		cout << "Please write a word. If you want to quit, write 0: ";
		getline(cin, input);
		if (input != "0")
			periodic(input, data);

	}

}
