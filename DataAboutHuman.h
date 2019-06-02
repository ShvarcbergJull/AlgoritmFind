#pragma once
#undef UNICODE
#include <fstream>
#include <Windows.h>
#include <locale.h>
#include <vector>
#include <iterator>
#include <map>
#include "Sort.h"
#include "Human.h"

using namespace std;

bool readHumans(const char* filename, SortVector<Human>& humans)
{
	ifstream in(filename);
	if (!in.is_open())
		return false;
	Human human;
	in >> human;
	while (!in.fail())
	{
		humans.push_back(human);
		in >> human;
	}
	in.close();
	return true;
}

bool readHumans(const char* filename, map<string, HumanData>& humans)
{
	ifstream in(filename);
	if (!in.is_open())
		return false;
	string name;
	HumanData data;
	getline(in, name, ';') >> data;
	while (!in.fail())
	{
		humans[name] = data;
		getline(in, name, ';') >> data;
	}
	in.close();
	return true;
}

string convert(string str)
{
	char* buf = new char[strlen(str.c_str() + 1)];
	OemToChar(str.c_str(), buf);
	string res(buf);
	//delete[] buf;
	return res;
}

Human FindByNameEnum(const SortVector<Human>& humans, const string& name)
{
	setlocale(LC_ALL, "Russian");
	cout << "Ищем: " << name << endl;
	for (vector<Human>::const_iterator it = humans.begin(); it != humans.end(); it++)
	{
		if (it->name == name)
			return (*it);
	}
	throw FindExeption();
}

Human FindByNameBin(const SortVector<Human>& humans, string& name, int min, int max)
{
	int index = (min + max) / 2;
	if (min > max)
		throw FindExeption();
	else if (humans[index].name == name)
		return humans[index];
	else if (humans[index].name > name)
		return FindByNameBin(humans, name, min, index - 1);
	else
		return FindByNameBin(humans, name, index + 1, max);
}

Human FindByNameBin(const SortVector<Human>& humans, string& name)
{
	cout << "Ищем: " << name << endl;
	return FindByNameBin(humans, name, 0, (int)humans.size() - 1);
}

void FindByNameMap(map<string, HumanData>& humans, string name)
{

	map<string, HumanData>::const_iterator it = humans.find(name);
	if (it != humans.end())
	{
		cout << "Человек найден" << endl;
		cout << it->first << ' ' << it->second << endl;
	}
	else
		cout << "Человек не найден: " << name << endl;
}
