#include "song.h"
#include <bits/stdc++.h>
using namespace std;


song::song(float width, float height)
{
	if (!font.loadFromFile("font.ttf"))
	{

	}

	//vector<string> vecname;

	vecname.push_back("THE BEGINNING");
	vecname.push_back("DEEPER DEEPER");
	vecname.push_back("MIGHTY LONG FALL");
	vecname.push_back("CRY OUT");
	vecname.push_back("C.H.A.O.S.M.Y.T.H");
	vecname.push_back("GO, VANTAGE POINT");
	vecname.push_back("Song 7");
	vecname.push_back("Song 8");
	vecname.push_back("Song 9");
	vecname.push_back("Song 10");

	for (int i = 0; i < MAX ; i++)
	{
		namesong[i].setFont(font);
		namesong[i].setFillColor(sf::Color::Black);
		namesong[i].setString(vecname[i]);
		namesong[i].setPosition(sf::Vector2f(width / 4, height / (MAX + 1) * (i+1)));
	}
	namesong[3].setFillColor(sf::Color::Red);
	selectedIndex = 3;
	number_song = 3;
	namesong[0].setFillColor(sf::Color(0, 0, 0, 96));
	namesong[1].setFillColor(sf::Color(0, 0, 0, 128));
	namesong[2].setFillColor(sf::Color(0, 0, 0, 191));
	namesong[4].setFillColor(sf::Color(0, 0, 0, 191));
	namesong[5].setFillColor(sf::Color(0, 0, 0, 128));
	namesong[6].setFillColor(sf::Color(0, 0, 0, 96));

	



}
song::~song()
{

}

void song::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("Pic/bg.jpg");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	window.draw(sprite);

	

	for (int i = 0; i < 7; i++)
	{
		window.draw(namesong[i]);
	}

}

void song::MoveUp()
{
	if (number_song == 0) number_song = MAX - 1;
	else number_song--;
		
		string mem = vecname[MAX - 1];
		for (int i = MAX - 1; i > 0; i--)
		{
			vecname[i] = vecname[i - 1];
		}
		vecname[0] = mem;
		for (int i = 0; i < MAX; i++)
		{
			namesong[i].setString(vecname[i]);
		}
		namesong[selectedIndex].setFillColor(sf::Color::Red);
}
void song::MoveDown()
{
	if (number_song == MAX - 1) number_song = 0;
	else number_song++;

	string mem = vecname[0];
	for (int i = 0; i < MAX-1; i++)
	{
		vecname[i] = vecname[i + 1];
	}
	vecname[MAX-1] = mem;
	for (int i = 0; i < MAX; i++)
	{
		namesong[i].setString(vecname[i]);
	}
	namesong[selectedIndex].setFillColor(sf::Color::Red);
}