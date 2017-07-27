//
// Created by Haleemur Ali on 2017-07-25.
//
#include <stdexcept>
#include <iostream>
#include <regex>
#include <random>
#include <numeric>
#include "SlotMachine.h"
#include "Rhombus.h"
#include "Rectangle.h"
#include "Isosceles.h"
#include "RightTriangle.h"
#include "Shape.h"

void SlotMachine::run()
{
	std::cout << "Welcome to this 3-Reel Slot Machine Game!\n"
              << "Each reel will randomly display one of for shapes, each in 25 sizes.\n"
              << "To win 3 times your bet you need 3 similar shapes of the same size.\n"
              << "To win 2 times your bet you need 3 similar shapes.\n"
              << "To win or lose nothing you need 2 similar shapes.\n"
              << "Otherwise, you lose your bet.\n"
              << "You start with 10 free tokens!\n";
//	int bet = -1;
	std::string input;
	do {
		try {
			std::cout << "How much would you like to bet? (enter 0 to quit) ";
			std::getline(std::cin, input);
			bet = read_input(input);
			if (bet > 0) {
				make_shapes();
				evaluate_bet();
				display_shapes();
				display_status();
				release_shapes();
			}
		} catch (const std::invalid_argument& e) {
			std::cout << e.what();
		}
	} while (bet != 0 && tokens != 0);
	std::cout << "Game Over. You now have " << tokens << " tokens\n";
}

SlotMachine::~SlotMachine()
{
	release_shapes();
}

void SlotMachine::release_shapes()
{
	for (auto shape : shape_reel) {
		delete shape;
	}
}

int SlotMachine::read_input(std::string iput)
{
	std::regex d("\\d+");
	int n;
	if (std::regex_match(iput, d)) {
		n = std::stoi(iput);
		if (n <= tokens) {
			return n;
		}
	}
	throw std::invalid_argument(input_err_message);
}

void SlotMachine::make_shapes()
{
	for (int i=0; i<shape_reel.size(); i++) {
		make_shape(i);
	}
}

void SlotMachine::make_shape(int r)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> shape_dist(0, 3);
	std::uniform_int_distribution<> size_dist(1, 25);

	int shape = shape_dist(gen);
	int width = size_dist(gen);

	delete shape_reel[r];
	if (shape == 0) {
		shape_reel[r] = new Rhombus(width);
	} else if (shape == 1) {
		shape_reel[r] = new Isosceles(width);
	} else if (shape == 2) {
		shape_reel[r] = new RightTriangle(width);
	} else {
		int height = size_dist(gen);
		shape_reel[r] = new Rectangle(width, height);
	}
}

void SlotMachine::display_shapes()
{
	std::array<std::vector<std::vector<char>>, 3> shapes = {
			shape_reel[0]->draw(),
			shape_reel[1]->draw(),
			shape_reel[2]->draw()};

	std::array<int, 3> widths = {
			shape_reel[0]->get_bbox_width(),
			shape_reel[1]->get_bbox_width(),
			shape_reel[2]->get_bbox_width()
	};


	std::array<int, 3> heights = {
			shape_reel[0]->get_bbox_height(),
			shape_reel[1]->get_bbox_height(),
			shape_reel[2]->get_bbox_height()
	};



	int height = *std::max_element(std::begin(heights), std::end(heights));


	display_boundary(widths);

	for (int i=0; i<height; ++i) {

		for (int j=0; j<3; j++) {
			std::cout << "| "; // lpad
			if (i < heights[j]) {
				// print row i of shape j
				for (int k=0; k < widths[j]; ++k) {
					std::cout << shapes[j].at(i).at(k);
				}
			} else {
				for (int k=0; k < widths[j]; ++k) {
					std::cout << " ";
				}
			}
			std::cout << " "; // rpad
		}
		std::cout << "|\n";
	}

	display_boundary(widths);

	for (auto shape : shape_reel) {
		std::cout << "(" << shape->get_name()
		          << ", " << shape->get_bbox_width()
		          << ", " << shape->get_bbox_height() << ") ";
	}
	std::cout << "\n";

}

void SlotMachine::evaluate_bet()
{
	if (shape_reel[0] == shape_reel[1]
	    && shape_reel[0] == shape_reel[2]) {
		result = 3;
	} else if (shape_reel[0]->get_name() == shape_reel[1]->get_name()
			&& shape_reel[0]->get_name() == shape_reel[2]->get_name()) {
		result = 2;
	} else if (shape_reel[0]->get_name() == shape_reel[1]->get_name()
            || shape_reel[0]->get_name() == shape_reel[2]->get_name()
            || shape_reel[1]->get_name() == shape_reel[2]->get_name()) {
		result = 0;
	} else {
		result = -1;
	}
	tokens += (result * bet);
}

void SlotMachine::display_status()
{
	if (result == 0) {
		std::cout << "You don't win, you don't lose, you are safe\n";
	} else if (result == -1) {
		std::cout << "You lose your bet\n";
	} else {
		std::cout << "Congratulations! You win " << result << " times your bet: " << bet << "\n";
	}
	std::cout << "You have " << tokens << " tokens!\n";
}

void SlotMachine::display_boundary(std::array<int, 3> widths) const
{
	for (auto width :widths) {
		std::cout << "+-";
		for (int i=0; i<width;++i) {
			std::cout << '-';
		}
		std::cout << "-";
	}
	std::cout << "+\n";
}