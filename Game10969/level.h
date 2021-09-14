#pragma once
#define MAX 3
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;

class level
{

public:
	level(float width, float height);
	~level();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int numlevel() { return number_level; }

private:
	int selectedIndex, number_level;
	vector<string> vecname;
	sf::Font font;
	sf::Text levelname[MAX];

};

