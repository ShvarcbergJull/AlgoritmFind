#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>

using namespace std;

const int STR_LENGHT = 100;

template <class T> class SortVector : public vector<T>
{
private:
	void sift(int root, int last);
public:
	void sort();
};

template <class T> void SortVector<T>::sort()
{
	for (int root = (*this).size() / 2 - 1; root >= 0; root--)
	{
		sift(root, (*this).size() - 1);
	}

	for (int last = (*this).size() - 1; last > 0; last--)
	{
		T temp = (*this)[0];
		(*this)[0] = (*this)[last];
		(*this)[last] = temp;
		sift(0, last - 1);
	}
}

template <class T> void SortVector<T>::sift(int root, int last)
{
	int free = root;
	T lastelem = (*this)[free];
	while (true)
	{
		int left = 2 * free + 1, right = 2 * free + 2;
		int max;

		if (left > last)
		{
			break;
		}
		else if (left == last)
		{
			max = left;
		}
		else
		{
			max = ((*this)[left] < (*this)[right]) ? right : left;
		}
		if ((*this)[max] <= lastelem)
			break;
		(*this)[free] = (*this)[max];
		free = max;
	}
	(*this)[free] = lastelem;
}
