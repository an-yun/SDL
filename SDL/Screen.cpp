#include "Screen.h"
#include "Swarm.h"
namespace paritcle_fire_explosion
{
	Screen::Screen(Swarm &s):
		window(nullptr), renderer(nullptr), texture(nullptr), buffer(nullptr), swarm(s),reverse(false)
	{

	}

	bool Screen::init()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			return false;
		}
		window = SDL_CreateWindow("Paritcle Fire Explosion",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			SDL_Quit();
			return false;
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
		if (renderer == nullptr)
		{
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;
		}
		if (texture == nullptr)
		{
			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(renderer);
			SDL_Quit();
			return false;
		}
		buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

		memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

		SDL_UpdateTexture(texture, nullptr, buffer, SCREEN_WIDTH*sizeof(Uint32));
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, nullptr, nullptr);
		SDL_RenderPresent(renderer);
		return true;
	}

	void Screen::update()
	{
		update(swarm);
		SDL_UpdateTexture(texture, nullptr, buffer, SCREEN_WIDTH*sizeof(Uint32));
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, nullptr, nullptr);
		SDL_RenderPresent(renderer);
	}

	void Screen::update(Swarm & swarm)
	{
		SDL_GetMouseState(&mouse_x, &mouse_y);
		swarm.update(mouse_x, mouse_y, reverse);
	}


	void Screen::clear()
	{
		memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
	}

	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
	{
		if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
			return;
		Uint32 color = 0;

		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xff;

		buffer[(y * SCREEN_WIDTH) + x] = color;
	}

	bool Screen::processEvent()
	{
		update();
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				return false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				reverse = true;
				break;
			case SDL_MOUSEBUTTONUP:
				reverse = false;
				break;
			default:
				return true;
			}
		}
		return true;
	}

	void Screen::close()
	{
		delete[] buffer;
		SDL_DestroyTexture(texture);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}


	Screen::~Screen()
	{
	}
}