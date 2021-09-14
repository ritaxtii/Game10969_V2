#include "level.h"
using namespace std;

level::level(float width, float height)
{
	if (!font.loadFromFile("font.ttf"))
	{

	}

	

	vecname.push_back("EASY");
	vecname.push_back("NORMAL");
	vecname.push_back("HARD");
	

	for (int i = 0; i < MAX; i++)
	{
		levelname[i].setFont(font);
		levelname[i].setString(vecname[i]);
		levelname[i].setPosition(sf::Vector2f(width / 4, height / (MAX + 10) * (i + 3)));
	}
	levelname[1].setFillColor(sf::Color::Red);
	selectedIndex = 1;
	number_level = 1;
	levelname[0].setFillColor(sf::Color(0, 0, 0, 191));
	levelname[1].setFillColor(sf::Color::Red);
	levelname[2].setFillColor(sf::Color(0, 0, 0, 191));
	





}
level::~level()
{

}

void level::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("Pic/bg.jpg");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	window.draw(sprite);



	for (int i = 0; i < 3; i++)
	{
		window.draw(levelname[i]);
	}

}

void level::MoveUp()
{
	if (number_level == 0) number_level = MAX - 1;
	else number_level--;

	string mem = vecname[MAX - 1];
	for (int i = MAX - 1; i > 0; i--)
	{
		vecname[i] = vecname[i - 1];
	}
	vecname[0] = mem;
	for (int i = 0; i < MAX; i++)
	{
		levelname[i].setString(vecname[i]);
	}
	levelname[selectedIndex].setFillColor(sf::Color::Red);
}
void level::MoveDown()
{
	if (number_level == MAX - 1) number_level = 0;
	else number_level++;

	string mem = vecname[0];
	for (int i = 0; i < MAX - 1; i++)
	{
		vecname[i] = vecname[i + 1];
	}
	vecname[MAX - 1] = mem;
	for (int i = 0; i < MAX; i++)
	{
		levelname[i].setString(vecname[i]);
	}
	levelname[selectedIndex].setFillColor(sf::Color::Red);
}
