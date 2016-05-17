#include "Swarm.h"

namespace paritcle_fire_explosion
{

	Swarm::Swarm():particles(NPARTICLES)
	{
	}


	void Swarm::update(int mouse_x, int mouse_y, bool reverse)
	{
		for (Particle &particle : particles)
			particle.update(mouse_x,mouse_y, reverse);
	}

	Swarm::~Swarm()
	{
	}
}