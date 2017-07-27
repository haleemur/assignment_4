//
// Created by Haleemur Ali on 2017-07-23.
//
#include <typeinfo>
#include "Shape.h"
#include <ostream>
#include <iostream>
#include <sstream>
#include <iomanip>


int Shape::serial = 0;

std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<char>> &grid)
{
	for (auto row : grid) {
		for (char col : row) {
			os << col;
		}
		os << '\n';
	}
	return os;
}

std::ostream &operator<<(std::ostream &os, const Shape &shape)
{
	os << shape.toString();
	return os;
}

void Shape::draw_on_screen(char penChar, char fillChar) const
{
	write_image_to_stream(std::cout, penChar, fillChar);
}

void Shape::write_image_to_stream(std::ostream &os, char penChar
                                  , char fillChar) const
{
	std::vector<std::vector<char>> g = draw(penChar, fillChar);
	os << g;
}


Shape::Shape(const std::string &n, const std::string &desc)
		: id(++serial),
		  name(n),
          description(desc)
{
	name = n;
	description = desc;
}

std::string Shape::toString() const
{
	std::stringstream ss;
	ss << std::fixed;
	ss <<  "Shape Information\n"
	   <<  "_________________\n"
	   <<  "Static type:   " <<  typeid(this).name() <<  "\n"
	   <<  "Dynamic type:  " <<  typeid(*this).name() <<  "\n"
	   <<  "Description:   " <<  description <<  "\n"
	   <<  "id:            " <<  id <<  "\n"
	   <<  "B. box width:  " <<  get_bbox_width() <<  "\n"
	   <<  "B. box height: " <<  get_bbox_height() <<  "\n"
	   <<  "Scr area:      " <<  scr_area() <<  "\n"
	   <<  "Geo area:      " <<  std::setprecision(2) << area() <<  "\n"
	   <<  "Scr perimeter: " <<  std::setprecision(0) << scr_perimeter() <<  "\n"
	   <<  "Geo perimeter: " <<  std::setprecision(2) << perimeter() <<  "\n";
	return ss.str();
}

std::string Shape::get_name()
{
	return name;
}

bool Shape::operator==(const Shape &rhs) const
{
	return name == rhs.name && area() == rhs.area() && get_bbox_height() && rhs.get_bbox_height();
}

bool Shape::operator!=(const Shape &rhs) const
{
	return !(rhs == *this);
}


