//
// Created by Haleemur Ali on 2017-07-23.
//

#ifndef SHAPES_RHOMBUS_H
#define SHAPES_RHOMBUS_H

#include "Shape.h"

class Rhombus: public Shape {
private:
	int d;
public:
	Rhombus(const int &diagonal, const std::string &desc);
	Rhombus(const int &diagonal);

	virtual ~Rhombus() = default;

	virtual int get_bbox_width() const override;
	virtual int get_bbox_height() const override;
	virtual std::vector<std::vector<char>>
	draw(char penChar='*', char fillChar=' ') const override;


	virtual double area() const override;
	virtual double perimeter() const override;
	virtual int scr_perimeter() const override;
	virtual int scr_area() const override;
	virtual void scale(int factor) override;
};


#endif //SHAPES_RHOMBUS_H
