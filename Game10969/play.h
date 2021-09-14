#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
class play
{

public:
	play(float width, float height);
	~play();

	void draw(sf::RenderWindow& window);
	void Music();


private:
	sf::Font font;
	sf::Music music;
	
};

