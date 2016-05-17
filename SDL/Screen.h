#pragma once
#include<SDL.h>
#include<memory.h>
#include "Swarm.h"
namespace paritcle_fire_explosion
{
	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;
	private:
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Texture *texture;
		Uint32 *buffer;
		SDL_Event event;
		Swarm &swarm;
		int mouse_x;
		int mouse_y;
		bool reverse;
	public:
		Screen(Swarm &s);
		bool init();
		void update();
		void update(Swarm &swarm);
		void clear();
		void setPixel(int x,int y,Uint8 red,Uint8 green,Uint8 blue);
		bool processEvent();
		void close();
		~Screen();
	};
}