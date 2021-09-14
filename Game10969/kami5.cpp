#include "kami5.h"
#include <bits/stdc++.h>

using namespace std;


kami5::kami5(float width, float height)
{
	if (!font.loadFromFile("font2.ttf"))
	{

	}

	FILE* fp;
	char name[100];
	char score[100];
	vector<pair<string, string>> vec;
	fp = fopen("Text.txt", "r+t");


	while (!feof(fp))
	{
		fgets(name, 100, fp);
		fgets(score, 100, fp);
		

		vec.push_back(make_pair(name, score));

	}
	fclose(fp);
	if (!vec.empty())
		vec.erase(vec.end() - 1);

	MAX_TOP_USER = vec.size();
	for (int i = 0; i < vec.size(); i++)
	{
		username[i].setFont(font);
		username[i].setScale(1.2f, 1.2f);
		username[i].setFillColor(sf::Color::Black);
		username[i].setString(vec[i].first);
		
		
	}
	username[0].setScale(1.5f, 1.5f);

	username[0].setPosition(sf::Vector2f(width / 3 -25, 200));
	username[1].setPosition(sf::Vector2f(width / 3 - 25, 275));
	username[2].setPosition(sf::Vector2f(width / 3 - 25, 340));
	username[3].setPosition(sf::Vector2f(width / 3 - 25, 405));
	username[4].setPosition(sf::Vector2f(width / 3 - 25, 470));
	for (int i = 0; i < vec.size(); i++)
	{
		userscore[i].setFont(font);
		userscore[i].setScale(1.2f, 1.2f);
		userscore[i].setFillColor(sf::Color::Black);
		userscore[i].setString(vec[i].second);
		
	}
	userscore[0].setScale(1.5f, 1.5f);
	userscore[0].setPosition(sf::Vector2f(width / 2 + 80, 200));
	userscore[1].setPosition(sf::Vector2f(width / 2 + 80, 275));
	userscore[2].setPosition(sf::Vector2f(width / 2 + 80, 340));
	userscore[3].setPosition(sf::Vector2f(width / 2 + 80, 405));
	userscore[4].setPosition(sf::Vector2f(width / 2 + 80, 470));

	
	skip.setFont(font);
	skip.setScale(1.f, 1.f);
	skip.setFillColor(sf::Color::Black);
	skip.setString("< press specebar to go back >");
	skip.setPosition(sf::Vector2f(width / 2 -200 ,670));
	
	

}
kami5::~kami5()
{

}

void kami5::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("Pic/bgkami.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	window.draw(sprite);

	for (int i = 0; i < MAX_TOP_USER; i++)
	{
		window.draw(username[i]);
		window.draw(userscore[i]);
	}
	window.draw(skip);


}
