//
// Created by Haleemur Ali on 2017-07-23.
//

#ifndef SHAPES_ISOTRIANGLE_H
#define SHAPES_ISOTRIANGLE_H

#include "Triangle.h"

class Isosceles: public Triangle {
private:
	int b, h;
	void set_height();
public:
	Isosceles(const int &base);
	Isosceles(const int &base, const std::string &desc);
	virtual void set_base(int b) override;
	virtual int get_height() const override;
	virtual int get_base() const override;
	virtual std::vector<std::vector<char>>
	draw(char penChar='*', char fillChar=' ') const override;
	virtual void scale(int factor) override;
	virtual double perimeter() const override;
	virtual int scr_perimeter() const override;
	virtual int scr_area() const override;
};


#endif //SHAPES_ISOTRIANGLE_H
