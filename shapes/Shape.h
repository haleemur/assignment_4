//
// Created by Haleemur Ali on 2017-07-23.
//

#ifndef SHAPES_SHAPE_H
#define SHAPES_SHAPE_H

#include <ostream>
#include <vector>
#include <sstream>

std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<char>> &grid);

class Shape {
private:
	std::string description;
	std::string name;
	const int id;
	static int serial;

public:
	Shape(const std::string &n, const std::string &desc);

	virtual ~Shape() = default;

	virtual int get_bbox_width() const = 0;
	virtual int get_bbox_height() const = 0;
	virtual std::vector<std::vector<char>>
	draw(char penChar='*', char fillChar=' ') const = 0;

	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual int scr_perimeter() const = 0;
	virtual int scr_area() const = 0;
	virtual void scale(int factor) = 0;

	bool operator==(const Shape &rhs) const;

	bool operator!=(const Shape &rhs) const;

	std::string get_name();
	friend std::ostream &operator<<(std::ostream &os, const Shape &shape);
	void write_image_to_stream(std::ostream &os, char penChar='*', char fillChar=' ') const;
	void draw_on_screen(char penChar='*', char fillChar=' ') const;
	std::string toString() const;
};


#endif //SHAPES_SHAPE_H
