#pragma once
#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

struct HumanData
{
	string addres;
	string phone;

	HumanData() {};
	HumanData(string adr, string ph);

	bool operator ==(const HumanData& hum) const
	{
		if (((*this).addres == hum.addres) && ((*this).phone == hum.phone))
			return true;
		return false;
	}

	bool operator >(const HumanData& dat) const
	{
		if ((*this).addres > dat.addres)
			return true;
		else
			if ((*this).addres == dat.addres)
				if ((*this).phone > dat.phone)
					return true;
		return false;
	}

	bool operator <(const HumanData& dat) const
	{
		if ((*this).addres < dat.addres)
			return true;
		else
			if ((*this).addres == dat.addres)
				if ((*this).phone < dat.phone)
					return true;
		return false;
	}

	void operator =(const HumanData& dat)
	{
		(*this).addres = dat.addres;
		(*this).phone = dat.phone;
	}
};

istream& operator >>(istream& in, HumanData& data)
{
	getline(in, data.addres, ';');
	getline(in, data.phone);
	return in;
}
ostream& operator <<(ostream& out, const HumanData& data)
{
	out << data.addres << ' ' << data.phone << endl;
	return out;
}

ostream& operator <<(char& str, const HumanData& data)
{
	cout << str;
	cout << data;
	return cout;
}

struct Human
{
	string name;
	HumanData data;
	Human() {};
	Human(string aname, string addr, string ph);

	bool operator ==(const Human& hum) const
	{
		if (((*this).name == hum.name) && ((*this).data == hum.data))
			return true;
		return false;
	}

	bool operator >(const Human& hum) const
	{
		if ((*this).name > hum.name)
			return true;
		else
			if ((*this).name == hum.name)
				if ((*this).data > hum.data)
					return true;
		return false;
	}

	bool operator <(const Human& hum) const
	{
		if ((*this).name < hum.name)
			return true;
		else
			if ((*this).name == hum.name)
				if ((*this).data < hum.data)
					return true;
		return false;
	}

	bool operator >=(const Human& hum) const
	{
		if (*this > hum || *this == hum)
			return true;
		return false;
	}

	bool operator <=(const Human& hum) const
	{
		if (*this < hum || *this == hum)
			return true;
		return false;
	}

	void operator =(const Human& hum)
	{
		(*this).name = hum.name;
		(*this).data = hum.data;
	}
};

istream& operator >>(istream& in, Human& data)
{
	getline(in, data.name, ';');
	in >> data.data;
	return in;
}
ostream& operator <<(ostream& out, const Human& data)
{
	out << data.name << ' ';
	out << data.data << endl;
	return out;
}

class FindExeption {};


Human::Human(string aname, string addr, string ph) : name(aname), data(addr, ph) {};

HumanData::HumanData(string addr, string ph)
{
	addres = addr;
	phone = ph;
}
