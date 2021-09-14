#include "play.h"

using namespace std;

play::play(float width, float height)
{
	
}
play::~play()
{

}

void play::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("Pic/bg.jpg");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	window.draw(sprite);

	sf::Texture texture2;
	texture2.loadFromFile("Pic/center.png");
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);
	sprite2.setPosition(sf::Vector2f(523,307));
	window.draw(sprite2);
	
}

void play::Music()
{
	music.play();
}

