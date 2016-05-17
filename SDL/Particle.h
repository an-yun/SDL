#pragma once
namespace paritcle_fire_explosion
{
	/*
	СЃзг
	*/
	class Particle
	{
	public:
		double x;
		double y;
	private:
		double speed_x;
		double speed_y;
	public:
		Particle();
		void update(int mouse_x, int mouse_y, bool reverse);
		~Particle();
	};
}
