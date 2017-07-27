//
// Created by Haleemur Ali on 2017-07-23.
//

#ifndef SHAPES_TRIANGE_H
#define SHAPES_TRIANGE_H

#include "Shape.h"

class Triangle : public Shape {

public:
	Triangle(const std::string &nm, const std::string &desc);
	virtual ~Triangle() = default;
	virtual void set_base(int b) = 0;
	virtual int get_base() const = 0;
	virtual int get_height() const = 0;
	virtual std::vector<std::vector<char>>
	draw(char penChar='*', char fillChar=' ') const override = 0 ;

	virtual int get_bbox_height() const override;
	virtual int get_bbox_width() const override;

	virtual void scale(int factor) override = 0;
	virtual double area() const override;
	virtual double perimeter() const override = 0;
	virtual int scr_perimeter() const override = 0;
	virtual int scr_area() const override = 0;
};


#endif //SHAPES_TRIANGE_H
