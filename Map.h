#pragma once
#include "lib\framework.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

//---------------------------------------------
//
//----------------- ƒ}ƒbƒv ---------------------
//
//---------------------------------------------


class Map {

private:

	Vec2f map_pos;
	Texture yuka = Texture("res/yellow_block.png");
	Texture block = Texture("res/blue_red_block.png");

	enum {
		CHIP_SIZE = 64,
	};

public:

	Map();
	void drawMap(AppEnv& env);
};