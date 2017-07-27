//
// Created by Haleemur Ali on 2017-07-25.
//

#ifndef SHAPES_SLOTMACHINE_H
#define SHAPES_SLOTMACHINE_H

#include "Shape.h"
#include <array>

class SlotMachine {
private:
	int tokens = 10;
	std::array<Shape*, 3> shape_reel;
	std::string input_err_message = "Error! All bets must be between 1 & available tokens\n";
	int result;
	int bet = -1;
	int read_input(std::string iput);
	void display_boundary(std::array<int, 3>widths) const;
	void make_shapes();
	void make_shape(int r);
	void display_shapes();
	void display_status();
	void release_shapes();
	void evaluate_bet();

public:
	SlotMachine() = default;
	SlotMachine(const SlotMachine&) = delete;
	SlotMachine &operator=(const SlotMachine&) = delete;
	void run();
	virtual ~SlotMachine();
};


#endif //SHAPES_SLOTMACHINE_H
