//
// Created by Haleemur Ali on 2017-07-23.
//

#include "Rhombus.h"
#include <cmath>

Rhombus::Rhombus(const int &diagonal) : Rhombus(diagonal, "Generic Rhombus"){}

double Rhombus::area() const
{
	return d * d / 2.0;
}

std::vector<std::vector<char>> Rhombus::draw(char penChar, char fillChar) const
{
	std::vector<std::vector<char>> grid;
	std::vector<char> row;
	int k;
	for (int i=0; i<d; i++) {

		k = i < d/2 ? i : d - i - 1;

		row.clear();
		for (int j=0; j<d/2-k; j++) { row.push_back(fillChar); }

		for (int j=d/2-k; j<=d/2+k; j++) { row.push_back(penChar); }

		for (int j=d/2+k+1; j<d; j++) { row.push_back(fillChar); }
		grid.push_back(row);
	}

	return grid;
}

int Rhombus::get_bbox_width() const
{
	return d;
}

int Rhombus::get_bbox_height() const
{
	return d;
}

void Rhombus::scale(int factor)
{
	d = d + (2 * factor) > 0 ? d : d + (2 * factor);
}

double Rhombus::perimeter() const
{
	return 2 * std::sqrt(2) * d;
}

int Rhombus::scr_perimeter() const
{
	return 2 * (d - 1);
}

int Rhombus::scr_area() const
{
	int n = d / 2;
	return 2 * n * (n + 1) + 1;
}

Rhombus::Rhombus(const int &diagonal, const std::string &desc)
		: Shape("Rhombus", desc)
{
	d = diagonal % 2 == 0 ? diagonal + 1 : diagonal;
}

