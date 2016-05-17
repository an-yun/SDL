#include "Particle.h"
#include "Screen.h"
#include <cstdlib>
#include <cmath>
namespace paritcle_fire_explosion
{

	Particle::Particle()
	{
		x = (2.0 * rand()) / RAND_MAX - 1;
		y = (2.0 * rand()) / RAND_MAX - 1;
		speed_x = ((2.0 * rand()) / RAND_MAX - 1)*0.005;
		speed_y = ((2.0 * rand()) / RAND_MAX - 1)*0.005;
	}

	void Particle::update(int mouse_x, int mouse_y, bool reverse)
	{

		int dx = mouse_x - int((x + 1)*Screen::SCREEN_WIDTH / 2);
		int dy = mouse_y - int((y + 1)*Screen::SCREEN_HEIGHT / 2);
		if (reverse)
		{
			dx = -dx;
			dy = -dy;
		}
		if (dx*dx+dy*dy > 25)
		{
			double a = sqrt(dx*dx + dy*dy);
			double v_x = dx / a*0.004;
			double v_y = dy / a*0.004;
			speed_x = (speed_x + v_x) / (1 + speed_x * v_x * 40000);
			speed_y = (speed_y + v_y) / (1 + speed_y * v_y * 40000);
		}
		x += speed_x;
		y += speed_y;
		if (x > 1 || x < -1)speed_x = -speed_x;
		if (y > 1 || y < -1)speed_y = -speed_y;
	}


	Particle::~Particle()
	{
	}
}