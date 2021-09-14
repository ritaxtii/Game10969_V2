#pragma once

#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3
class menu
{
public:
	menu(float width, float height);
	~menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedIndex; }

private:
	int selectedIndex;
	sf::Font font;
	//sf::Text Menu[MAX_NUMBER_OF_ITEMS];
	sf::Sprite Menu[MAX_NUMBER_OF_ITEMS];

};

