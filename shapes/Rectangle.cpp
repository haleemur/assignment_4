//
// Created by Haleemur Ali on 2017-07-23.
//

#include "Rectangle.h"

Rectangle::Rectangle(const int &width, const int &height): Rectangle(width, height, "Generic Rectangle") {}

double Rectangle::area() const
{
	return w * h;
}

std::vector<std::vector<char>>
Rectangle::draw(char penChar, char fillChar) const
{
	std::vector<std::vector<char>> grid;
	std::vector<char> row;
	for (int i=0;i<w;++i) { row.push_back(penChar); }
	for (int i=0;i<h;i++) { grid.push_back(row); }
	return grid;
}

void Rectangle::scale(int factor)
{
	if (w+factor > 0 && h+factor > 0) {
		w += factor;
		h += factor;
	}
}

int Rectangle::get_bbox_width() const
{
	return w;
}

int Rectangle::get_bbox_height() const
{
	return h;
}

double Rectangle::perimeter() const
{
	return 2 * (h + w);
}

int Rectangle::scr_perimeter() const
{
	return 2 * (h + w) - 4;
}

int Rectangle::scr_area() const
{
	return h*w;
}

Rectangle::Rectangle(const int &width, const int &height
                     , const std::string &desc)
	: Shape("Rectangle", desc)
{
	w = width;
	h = height;
}
