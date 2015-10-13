#include "lib/framework.hpp"
#include "Map.h"



// アプリのウインドウサイズ
enum Window {
	WIDTH = 1024,
	HEIGHT = 1024
};



int main() {

	AppEnv env(Window::WIDTH, Window::HEIGHT, 
		       false, true);

	Map map;
	

	//bool map_flag = true;

	while (1) {

		// 開始
		env.begin();

		map.drawMap(env);

		// 終了
		env.end();

	}
}
