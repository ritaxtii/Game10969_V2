#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;

#define MAX 5
class kami5
{
public:
	kami5(float width, float height);
	~kami5();
	void draw(sf::RenderWindow& window);
private :
	sf::Font font;
	sf::Text username[MAX];
	sf::Text userscore[MAX];
	sf::Text skip;
	int MAX_TOP_USER;
	
};