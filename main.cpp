#include <iostream>
#include "RightTriangle.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Isosceles.h"
#include "Shape.h"
#include "SlotMachine.h"

int main()
{
	Rectangle shape1(10, 3);
	std::cout << shape1 << "\n\n";

	Rhombus ace(16, "Ace of diamond");
	std::cout << ace << std::endl;
	std::cout << "using toString()\n";
	std::cout << ace.toString() << "\n\n";

	Isosceles iso(17);
	std::cout << iso << "\n\n";

	Rhombus *rhombus = new Rhombus(10);
	rhombus->draw_on_screen('+', '=');
	RightTriangle rt(10, "Carpenter's Square");
	std::cout << rt << "\n\n";

	std::cout << shape1.draw() << "\n\n";
	std::cout << ace.draw('o') << "\n\n";
	std::cout << iso.draw('\\', '.') << "\n\n";
	std::cout << rt.draw('+', '-') << "\n\n";
	ace.draw_on_screen(' ', '0');
	ace.scale(-4);
	ace.write_image_to_stream(std::cout, '1');
	ace.scale(2);
	ace.write_image_to_stream(std::cout, 'A', '.');
	std::cout << "\n\n";

	SlotMachine slot_machine;
	slot_machine.run();
	return 0;
}