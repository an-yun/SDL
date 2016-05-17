#pragma once
#include<vector>
#include "Particle.h"
namespace paritcle_fire_explosion
{
	/*
	Á£×ÓÈº
	*/
	class Swarm
	{
	public:
		const static int NPARTICLES = 5000;
	private:
		std::vector<Particle> particles;
	public:
		Swarm();
		const std::vector<Particle> &getParticles() { return particles; }
		void update(int mouse_x,int mouse_y,bool reverse);
		~Swarm();
	};
}
