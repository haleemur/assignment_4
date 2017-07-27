//
// Created by Haleemur Ali on 2017-07-23.
//

#include "Triangle.h"

double Triangle::area() const
{
	return get_base() * get_height() / 2.0;
}

int Triangle::get_bbox_width() const
{
	return get_base();
}

int Triangle::get_bbox_height() const
{
	return get_height();
}

Triangle::Triangle(const std::string &nm, const std::string &desc)
		: Shape(nm, desc) {}
