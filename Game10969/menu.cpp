#include "menu.h"

menu::menu(float width, float height)
{
	/*if (!font.loadFromFile("font.ttf"))
	{

	}*/
	
	/*
	Menu[0].setFont(font);
	Menu[0].setFillColor(sf::Color::Red);
	Menu[0].setString("Play");
	Menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	Menu[1].setFont(font);
	Menu[1].setFillColor(sf::Color::Black);
	Menu[1].setString("Options");
	Menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	Menu[2].setFont(font);
	Menu[2].setFillColor(sf::Color::Black);
	Menu[2].setString("Exit");
	Menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));*/
	Menu[1].setScale(1.1, 1.1f);
	selectedIndex = 1;


}
menu::~menu()
{

}

void menu::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("Pic/bg.jpg");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	window.draw(sprite);

	sf::Texture texture2;
	texture2.loadFromFile("Pic/logo.png");
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);
	sprite2.setPosition(173, 63);
	window.draw(sprite2);
	
	sf::Texture tex[MAX_NUMBER_OF_ITEMS];
	tex[0].loadFromFile("Pic/Kami5.png");
	Menu[0].setTexture(tex[0]);
	Menu[0].setPosition(82, 360);

	tex[1].loadFromFile("Pic/Play.png");
	Menu[1].setTexture(tex[1]);
	Menu[1].setPosition(408, 253);

	tex[2].loadFromFile("Pic/Exit.png");
	Menu[2].setTexture(tex[2]);
	Menu[2].setPosition(733, 360);
	
	
	
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(Menu[i]);
	}
	
}

void menu::MoveUp()
{
	if(selectedIndex - 1 >= 0 )
	{
		
		Menu[selectedIndex].setScale(1, 1);
		selectedIndex--;
		Menu[selectedIndex].setScale(1.1f, 1.1f);

	}
}
void menu::MoveDown()
{
	if (selectedIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		Menu[selectedIndex].setScale(1, 1);
		selectedIndex++;
		Menu[selectedIndex].setScale(1.1f, 1.1f);

	}
}