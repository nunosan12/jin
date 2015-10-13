//---------------------------------------------
//
//----------------- ƒ}ƒbƒv ---------------------
//
//---------------------------------------------

#include "Map.h"
#include "Player.h"

Map::Map()
{
	map_pos(0, 0);

}


void Map::drawMap(AppEnv& env) {

	Player player;

	int map[56][32];

	int x, y;

	

	std::ifstream mapfile("res/mapchip.txt");
	for (y = 0; y < 56; y += 1) {
		for (x = 0; x < 32; x += 1) {
			mapfile >> map[y][x];
			
		}
	}

	bool map_flag = true;
	if (map_flag) {


		const char* mapfile = "res/mapchip.txt";
		std::ifstream* list = new std::ifstream(mapfile);

		for (y = 0; y < 56; y += 1) {
			for (x = 0; x < 32; x += 1) {
				*list >> map[y][x];
				//map[y][x] = 0, 1;
				std::cout << map[y][x];
				
			}
			std::cout << std::endl;
		}

		if (!env.isOpen()) exit(0);
		{
			std::fstream file;
			file.open("res/mapchip.txt", std::ios::out | std::ios::binary);
			for (y = 0; y < 56; y += 1) {
				for (x = 0; x < 32; x += 1) {
					float x_offset = (map[y][x] % 1) * CHIP_SIZE;
					float y_offset = (map[y][x] / 1) * CHIP_SIZE;

					file << map[y][x] << ' ';

					if (map[y][x] == 0) {
						drawTextureBox(map_pos.x() + (x * CHIP_SIZE), map_pos.y() - (y * CHIP_SIZE), CHIP_SIZE, CHIP_SIZE,
							x_offset, y_offset, 64, 64, yuka, Color::white, 0.0, Vec2f(1.0, 1.0), Vec2f(32, 32));
					}
					if (map[y][x] == 1) {
						drawTextureBox(map_pos.x() + (x * CHIP_SIZE), map_pos.y() - (y * CHIP_SIZE), CHIP_SIZE, CHIP_SIZE,
							x_offset, y_offset, 64, 64, block, Color::white, 0.0, Vec2f(1.0, 1.0), Vec2f(32, 32));

						player.HitBlocks(map_pos.x() + (x * CHIP_SIZE), map_pos.y() - (y * CHIP_SIZE), CHIP_SIZE, CHIP_SIZE);

					}
					
					
				}
				file << std::endl;
			}
			file.close();

			
			


		}
		
		player.Move(env, map_pos);

	}
	env.flushInput();
}

