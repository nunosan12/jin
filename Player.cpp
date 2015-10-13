//--------------------------------------------
//
//--------------- ÉvÉåÉCÉÑÅ[ ------------------
//
//--------------------------------------------

#include "Player.h"


Player::Player()
{
	pos = Vec2f(0, 0);
	vec = Vec2f::Zero();
	size = Vec2f(64, 64);
	//rotate = 0;
	speed = 15.0f;


}

float Player::rotate = 0;


void Player::Move(AppEnv& env, Vec2f& map_pos) {


	if (env.isPressKey(GLFW_KEY_RIGHT) && !env.isPressKey(GLFW_KEY_UP) && !env.isPressKey(GLFW_KEY_DOWN)){

		//pos.x() += speed;
		 rotate = 2 * M_PI / 360 * -90;
		 map_pos.x() -= speed;

		 
	}
	




	if (env.isPressKey(GLFW_KEY_LEFT) && !env.isPressKey(GLFW_KEY_UP) && !env.isPressKey(GLFW_KEY_DOWN)){

		//pos.x() -= speed;
		rotate = 2 * M_PI / 360 * +90;
		map_pos.x() += speed;
	}
		

	if (env.isPressKey(GLFW_KEY_UP) && !env.isPressKey(GLFW_KEY_LEFT) && !env.isPressKey(GLFW_KEY_RIGHT)){

		//pos.y() += speed;
		rotate = 2 * M_PI / 360 * 0;
		map_pos.y() -= speed;
	}
	




	if (env.isPressKey(GLFW_KEY_DOWN) && !env.isPressKey(GLFW_KEY_LEFT) && !env.isPressKey(GLFW_KEY_RIGHT)){

		//pos.y() -= speed;
		rotate = 2 * M_PI / 360 * -180;
		map_pos.y() += speed;
	}
	
	Draw();


};

void Player::Draw() {

	drawTextureBox(pos.x(), pos.y(), size.x(), size.y(),
		0, 0, 64, 64,
		mycar_pic,
		Color::white,
		rotate,
		Vec2f(0.85, 0.85),
		Vec2f(32, 32));

	



};

void Player::HitBlocks(float block_posx, float block_posy,
	                   float block_width, float block_height) {

	if ((pos.x() < block_posx - 10 + block_width)
		&& (block_posx + 10 < pos.x() + size.x())
		&& (pos.y() < block_posy - 10 + block_height)
		&& (block_posy + 10 < pos.y() + size.y())) {

		

		if (pos.x() + size.x() > block_posx - 10) {
			
			speed = -speed;
			pos.x() = block_posx - 10 - size.x();

			drawCircle(pos.x(), pos.y(), 100, 100, 100, 5, Color::blue);
		}
		if (block_width < pos.x()) {

			speed = -speed;
			pos.x() = block_width;

			drawCircle(pos.x(), pos.y(), 100, 100, 100, 5, Color::blue);
		}

		if (pos.y() + size.y() > block_posy + 10) {

			pos.y() = block_posy + 10 - size.y();

			drawCircle(pos.x(), pos.y(), 100, 100, 100, 5, Color::blue);
		}
		if (block_height < pos.y()) {

			pos.y() = block_height;

			drawCircle(pos.x(), pos.y(), 100, 100, 100, 5, Color::blue);
		}


	}
}