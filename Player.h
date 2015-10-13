#pragma once
#include "lib/framework.hpp"
#include <iostream>

//--------------------------------------------
//
//--------------- ÉvÉåÉCÉÑÅ[ ------------------
//
//--------------------------------------------


class Player{

private:

	Vec2f pos;
	Vec2f vec;
	Vec2f size;
	float speed;

	Texture mycar_pic = Texture("res/Mycar.png");

public:

	static float rotate;
	

	Player();
	void Move(AppEnv& env, Vec2f& map_pos);
	void Draw(); 
	void HitBlocks(float block_posx, float block_posy, 
				   float block_widht, float block_height);
};

