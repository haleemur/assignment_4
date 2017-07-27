//
// Created by Haleemur Ali on 2017-07-23.
//

#ifndef SHAPES_RECTANGLE_H
#define SHAPES_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape{
private:
	int w, h;
public:
	Rectangle(const int &width, const int &height);
	Rectangle(const int &width, const int &height, const std::string &desc);
	virtual ~Rectangle() = default;
	virtual double area() const override;
	virtual std::vector<std::vector<char>>
	draw(char penChar='*', char fillChar=' ') const override;
	virtual void scale(int factor) override;
	virtual int get_bbox_width() const override;
	virtual int get_bbox_height() const override;
	virtual double perimeter() const override;
	virtual int scr_perimeter() const override;
	virtual int scr_area() const override;
};


#endif //SHAPES_RECTANGLE_H
