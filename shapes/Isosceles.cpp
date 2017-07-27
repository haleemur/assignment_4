//
// Created by Haleemur Ali on 2017-07-23.
//

#include "Isosceles.h"
#include <cmath>

Isosceles::Isosceles(const int &base)
		: Isosceles(base, "Generic Isosceles"){}

void Isosceles::set_base(int base)
{
	b =  base % 2 == 0 ? base + 1 : base;
	set_height();
}


std::vector<std::vector<char>> Isosceles::draw(char penChar, char fillChar) const
{
	std::vector<std::vector<char>> grid;
	std::vector<char> row;
	for (int i=0; i<h; ++i) {
		row.clear();
		for (int j=0; j<b/2-i;++j) { row.push_back(fillChar); }
		for (int j=b/2-i;j<=b/2+i;++j) { row.push_back(penChar); }
		for (int j=b/2+i+1; j<b;++j) { row.push_back(fillChar); }
		grid.push_back(row);
	}

	return grid;
}

void Isosceles::set_height()
{
	h = (b + 1) / 2;
}

int Isosceles::get_height() const
{
	return h;
}
int Isosceles::get_base() const
{
	return b;
}

void Isosceles::scale(int factor)
{
	b = b + (2*factor) > 0 ? b + (2*factor) : b;
	set_height();
}

double Isosceles::perimeter() const
{
	return b + 2 * std::sqrt(0.25 * b * b + h * h);
}

int Isosceles::scr_perimeter() const
{
	return 4 * (h - 1);
}

int Isosceles::scr_area() const
{
	return h * h;
}

Isosceles::Isosceles(const int &base, const std::string &desc)
	: Triangle("Isosceles", desc)
{
	set_base(base);
}

