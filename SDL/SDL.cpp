#include <iostream>
#include <SDL.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Screen.h"
#include "Swarm.h"
using namespace paritcle_fire_explosion;
int main(int argc, char **argv)
{
	srand((unsigned)time(nullptr));
	Swarm swarm;
	Screen screen(swarm);
	if (!screen.init())
	{
		std::cout << "Error initialising SDL." << std::endl;
		return 0;
	}
	
	while (true)
	{
		//Update particles
		//Draw particles
		//SDL_Delay(30);
		screen.clear();
		int elapsed = SDL_GetTicks();
		Uint8 red = (Uint8)((1 + sin(elapsed*0.0001)) * 128);
		Uint8 green = (Uint8)((1 + sin(elapsed*0.0002)) * 128);
		Uint8 blue = (Uint8)((1 + sin(elapsed*0.0003)) * 128);
		for (auto &particle : swarm.getParticles())
		{
			int x = (int)((particle.x + 1)*Screen::SCREEN_WIDTH / 2);
			int y = (int)((particle.y + 1)*Screen::SCREEN_HEIGHT / 2);
			screen.setPixel(x, y, red, green, blue);
		}
		//Draw the screen
		screen.update();
		//Check for messages/events
		if (!screen.processEvent())
			break;
	}
	screen.close();
	return 0;
}