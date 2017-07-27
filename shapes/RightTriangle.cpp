//
// Created by Haleemur Ali on 2017-07-23.
//
#include <cmath>
#include "RightTriangle.h"

RightTriangle::RightTriangle(const int &base) : RightTriangle(base, "Generic Right Triangle"){}

void RightTriangle::set_base(int base)
{
	b = base;
}

std::vector<std::vector<char>> RightTriangle::draw(char penChar, char fillChar) const
{
	std::vector<std::vector<char>> grid;
	std::vector<char> row;
	for (int i=0; i<b; ++i) {
		row.clear();
		for (int j=0;j<=i;j++) { row.push_back(penChar); }
		for (int j=i+1;j<b;++j) { row.push_back(fillChar); }
		grid.push_back(row);
	}
	return grid;
}

int RightTriangle::get_height() const
{
	return b;
}

int RightTriangle::get_base() const
{
	return b;
}

void RightTriangle::scale(int factor)
{
	b = b + factor > 0 ? b + factor : b;
}

double RightTriangle::perimeter() const
{
	return (2 + std::sqrt(2)) * b;
}

int RightTriangle::scr_perimeter() const
{
	return 3*(b-1);
}

int RightTriangle::scr_area() const
{
	return b*(b+1)/2;
}

RightTriangle::RightTriangle(const int &base, const std::string &desc)
		: Triangle("Right Triangle", desc)
{
	set_base(base);
}
