//
// Created by Haleemur Ali on 2017-07-23.
//

#ifndef SHAPES_RIGHTTRIANGLE_H
#define SHAPES_RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle: public Triangle {
private:
	int b;
public:
	RightTriangle(const int &base);
	RightTriangle(const int &base, const std::string &desc);
	virtual std::vector<std::vector<char>>
	draw(char penChar='*', char fillChar=' ') const override;
	virtual void set_base(int base) override;
	virtual int get_height() const override;
	virtual int get_base() const override;
	virtual void scale(int factor) override;
	virtual double perimeter() const override;
	virtual int scr_perimeter() const override;
	virtual int scr_area() const override;
};


#endif //SHAPES_RIGHTTRIANGLE_H
