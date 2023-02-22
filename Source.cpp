#include <SFML/Graphics.hpp>
#include <windows.h>

using namespace sf;

int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 64;

	RenderWindow window(VideoMode(1280, 720), "Goalkeepeer", Style::Default, settings);

	Texture land;
	land.loadFromFile("img/land.jpg");
	Sprite map;
	map.setTexture(land);

	Texture robot1;
	robot1.loadFromFile("img/robot1.png");
	Sprite rob;
	rob.setTexture(robot1);
	rob.scale(0.5, 0.5);
	rob.setPosition(300, 330);

	Texture robot2;
	robot2.loadFromFile("img/robot2.png");
	Texture robot3;
	robot2.loadFromFile("img/robot3.png");
	
	Texture x;
	int i = 0;

	while (window.isOpen())
	{
		Sleep(5000);

		window.draw(map);

		if (i == 0)
		{
			x = robot2;
			i = 1;
		}
		else
		{
			x = robot3;
			i = 0;
		}
		rob.setTexture(x);
		window.draw(rob);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.display();
	}
	return 0;
}