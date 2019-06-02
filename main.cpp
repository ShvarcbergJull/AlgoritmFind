#include <iostream>
#include <ctime>
#include "DataAboutHuman.h"

using namespace std;

int main()
{
	int start_time;
	setlocale(LC_ALL, "Russian");
	const char* filename = "tel.txt";
	SortVector<Human> humans_vec;
	map<string, HumanData> humans_map;

	if (!readHumans(filename, humans_vec))
	{
		cout << "Can't open input file" << endl;
		return -1;
	}

	if (!readHumans(filename, humans_map))
	{                                                                                                                                                                          
		cout << "Can't open input file" << endl;
		return -1;
	}

	string str;
	cout << "Введите фамилию, имя и отчество: " << endl;
	getline(cin, str);
	string name = convert(str);

	start_time = clock();
	cout << FindByNameEnum(humans_vec, name) << endl;
	int searc1 = clock() - start_time;
	humans_vec.sort();

	start_time = clock();
	cout << FindByNameBin(humans_vec, name) << endl;
	int searc2 = clock() - start_time;
	start_time = clock();
	FindByNameMap(humans_map, name);
	int searc3 = clock() - start_time;
	cout << endl;

	cout << "Time: " << endl << "1 - " << searc1 << endl;
	cout << "2 - " << searc2 << endl;
	cout << "3 - " << searc3 << endl;

	system("pause");
	return 0;
}
