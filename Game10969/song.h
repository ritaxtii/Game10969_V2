#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;

#define MAX 10
class song
{
public:
	song(float width, float height);
	~song();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int numsong() { return number_song; }

private:
	int selectedIndex,number_song;
	vector<string> vecname;
	sf::Font font;
	sf::Text namesong[MAX];
	
};

