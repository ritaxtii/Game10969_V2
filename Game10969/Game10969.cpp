#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <bits/stdc++.h>
#include "menu.h"
#include "song.h"
#include "level.h"
#include "kami5.h"
#include "play.h"

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define __STD_WANT_LIB_EXIT__ 1


using namespace std;

vector<string> file_song;
sf::RenderWindow window(sf::VideoMode(1152, 720), "10969");
vector <pair< pair<int,sf::Sprite>,int >> vec;
vector<sf::Sprite> gopop;
sf::Texture popup[4];
sf::Sprite S[4];
sf::Sprite sprite[4];
sf::Texture tex[4];
int good = -1;
char L, R , T , U;
string to_string(int num);
bool check(char s, sf::Event event);
int plusL(int position, int n);
void random(int numlevel, int numsong, long long t);


int main()
{
    sf::Music music;
    int stage = 1;
    int mem = 0;
   
    
    int numsong=0;
    int numlevel=0;
    menu Menu(window.getSize().x, window.getSize().y);
    song Song(window.getSize().x, window.getSize().y);
    level Level(window.getSize().x, window.getSize().y);
    kami5 Kami5(window.getSize().x, window.getSize().y);
    play Play(window.getSize().x, window.getSize().y);
    sf::Clock cl;
    long long int s = 0;
    
    file_song.push_back("song/song0.wav");
    file_song.push_back("song/song1.wav");
    file_song.push_back("song/song2.wav");
    file_song.push_back("song/song3.wav");
    file_song.push_back("song/song4.wav");
    file_song.push_back("song/song5.wav");
    file_song.push_back("song/song6.wav");
    file_song.push_back("song/song7.wav");
    file_song.push_back("song/song8.wav");
    file_song.push_back("song/song9.wav");
    file_song.push_back("song/song10.wav");

    
    
    popup[0].loadFromFile("Pic/n1.png");
    S[0].setTexture(popup[0]);
    S[0].setPosition(sf::Vector2f(507.5, 270));

    popup[1].loadFromFile("Pic/n2.png");
    S[1].setTexture(popup[1]);
    S[1].setPosition(sf::Vector2f(507.5, 270));

    popup[2].loadFromFile("Pic/n3.png");
    S[2].setTexture(popup[2]);
    S[2].setPosition(sf::Vector2f(507.5, 270));

    popup[3].loadFromFile("Pic/n4.png");
    S[3].setTexture(popup[3]);
    S[3].setPosition(sf::Vector2f(507.5, 270));

    sf::Text Score;
    sf::Font font;
    font.loadFromFile("font.ttf");
    Score.setFont(font);
    Score.setFillColor(sf::Color::Black);
    Score.setString("0");
    Score.setPosition(sf::Vector2f(1000,0));
    
    
    string st;
        
    long long time;

    while (window.isOpen())
    {
        
        sf::Event event;
        time = cl.getElapsedTime().asMilliseconds();

        //play
        if (stage == 4)
        {
            Play.draw(window);
            window.draw(Score);
            Score.setString(to_string(s));
            if (good != -1) window.draw(S[good]);
            for (int i = 0; i < vec.size(); i++)
            {
                if (vec[i].first.second.getPosition().x > 523 && vec[i].second == 0)
                {
                    vec.erase(vec.begin());
                }
                else if (vec[i].first.second.getPosition().x < 523 && vec[i].second == 1)
                {
                    vec.erase(vec.begin());
                }
                else if (vec[i].first.second.getPosition().y > 307 && vec[i].second == 2)
                {
                    vec.erase(vec.begin());
                }
                else if (vec[i].first.second.getPosition().y < 307 && vec[i].second == 3)
                {
                    vec.erase(vec.begin());
                }
                else break;
            }
            for (int i = 0; i < vec.size(); i++)
            {
                
                if (vec[i].first.first <= time + 4000 && vec[i].first.first <= time)
                {
                    if (vec[i].second == 0 && vec[i].first.second.getPosition().x <= 523)
                    {
                        window.draw(vec[i].first.second);
                        vec[i].first.second.move(5.f, 0.0f);

                    }
                    else if (vec[i].second == 1 && vec[i].first.second.getPosition().x >= 523)
                    {
                        window.draw(vec[i].first.second);
                        vec[i].first.second.move(-5.f, 0.0f);
                    }
                    else if (vec[i].second == 2 && vec[i].first.second.getPosition().y <= 307)
                    {
                        window.draw(vec[i].first.second);
                        vec[i].first.second.move(0.f, 5.0f);
                    }
                    else if (vec[i].second == 3 && vec[i].first.second.getPosition().y >= 307)
                    {
                        window.draw(vec[i].first.second);
                        vec[i].first.second.move(0.f, -5.0f);
                    }
                    if (vec[i].first.first > time + 4000) break;
                }
            }

            
            while (window.pollEvent(event))
            {
                if (sf::Event::KeyReleased && !vec.empty())
                {
                    if (vec[0].second == 0 && check(L, event)) s += plusL(vec[0].first.second.getPosition().x,523);
                    if (vec[0].second == 1 && check(R, event)) s += plusL(vec[0].first.second.getPosition().x, 523);
                    if (vec[0].second == 2 && check(T, event)) s += plusL(vec[0].first.second.getPosition().y, 307);
                    if (vec[0].second == 3 && check(U, event)) s += plusL(vec[0].first.second.getPosition().y, 307);
                    cout << s << endl;
                }
            }
        
            
            //cout << vec.size() << endl;

            window.display();
        }

        //Menu
        else if (stage == 1)
        {
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Left:
                        Menu.MoveUp();
                        break;
                    case sf::Keyboard::Right:
                        Menu.MoveDown();
                        break;
                    case sf::Keyboard::Return:
                        switch (Menu.GetPressedItem())
                        {
                            //Kami5
                        case 0:
                            stage = -1;
                            break;
                            //Play
                        case 1:
                            stage = 2;
                            break;
                            //Exit
                        case 2:
                            window.close();
                            break;


                        }
                    }


                }
                if (event.type == sf::Event::Closed)
                    window.close();
            }


            window.clear();
            Menu.draw(window);
            window.display();
        }

        //choose song
        else if (stage == 2)
        {
            
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        Song.MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        Song.MoveDown();
                        break;
                    case sf::Keyboard::Return:
                        numsong = Song.numsong();
                        cout << numsong << endl;
                        stage = 3;
                        break;
                    }


                }
                if (event.type == sf::Event::Closed)
                    window.close();
            }


            window.clear();
            Song.draw(window);
            window.display();
        }

        //choose level
        else if (stage == 3)
        {
            window.clear();
            Level.draw(window);
            window.display();
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        Level.MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        Level.MoveDown();
                        break;
                    case sf::Keyboard::Return:
                        numlevel = Level.numlevel();
                        cout << "level" << numlevel << endl;
                        music.openFromFile(file_song[numsong]);
                        random(numlevel,numsong,time);
                        music.play();
                        cl.restart();
                        stage = 4;
                        break;
                    }


                }
                if (event.type == sf::Event::Closed)
                    window.close();
            }


            
        }

        
       
        //kami5
        else if (stage == -1)
        {

            while (window.pollEvent(event))
            {
          
                if (event.type == sf::Event::Closed)
                    window.close();
                switch (event.key.code)
                {
                case sf::Keyboard::Space:
                    stage = 1;
                    break;
                }
            }
            window.clear();
            Kami5.draw(window);
            window.display();
        }

        //login
        else if (stage == -2)
        {
            
        }

    }

    
    return 0;
}
string to_string(int num)
{
    ostringstream os;
    os << num;
    return os.str();
}
bool check(char s, sf::Event event)
{
    cout << s;

    if (s == 'A' && event.key.code == sf::Keyboard::A) return true;
    else if (s == 'B' && event.key.code == sf::Keyboard::B) return true;
    else if (s == 'C' && event.key.code == sf::Keyboard::C) return true;
    else if (s == 'D' && event.key.code == sf::Keyboard::D) return true;
    else if (s == 'E' && event.key.code == sf::Keyboard::E) return true;
    else if (s == 'F' && event.key.code == sf::Keyboard::F) return true;
    else if (s == 'G' && event.key.code == sf::Keyboard::G) return true;
    else if (s == 'H' && event.key.code == sf::Keyboard::H) return true;
    else if (s == 'I' && event.key.code == sf::Keyboard::I) return true;
    else if (s == 'J' && event.key.code == sf::Keyboard::J) return true;
    else if (s == 'K' && event.key.code == sf::Keyboard::K) return true;
    else if (s == 'L' && event.key.code == sf::Keyboard::L) return true;
    else if (s == 'M' && event.key.code == sf::Keyboard::M) return true;
    else if (s == 'N' && event.key.code == sf::Keyboard::N) return true;
    else if (s == 'O' && event.key.code == sf::Keyboard::O) return true;
    else if (s == 'P' && event.key.code == sf::Keyboard::P) return true;
    else if (s == 'Q' && event.key.code == sf::Keyboard::Q) return true;
    else if (s == 'R' && event.key.code == sf::Keyboard::R) return true;
    else if (s == 'S' && event.key.code == sf::Keyboard::S) return true;
    else if (s == 'T' && event.key.code == sf::Keyboard::T) return true;
    else if (s == 'U' && event.key.code == sf::Keyboard::U) return true;
    else if (s == 'V' && event.key.code == sf::Keyboard::V) return true;
    else if (s == 'W' && event.key.code == sf::Keyboard::W) return true;
    else if (s == 'X' && event.key.code == sf::Keyboard::X) return true;
    else if (s == 'Y' && event.key.code == sf::Keyboard::Y) return true;
    else if (s == 'Z' && event.key.code == sf::Keyboard::Z) return true;
    else return false;

}
int plusL(int position, int n)
{
    int x = abs(n - position);

    if (x <= 106)
    {
        int  s = ((106 - x) * 100) / 106;
        if (s >= 95) good = 0;
        else if (s >= 75) good = 1;
        else if (s >= 50) good = 2;
        else good = 3;
        return s;
    }
    else return 0;
    if (!vec.empty()) vec.erase(vec.begin());
}
void random(int numlevel, int numsong, long long t)
{
    srand(time(NULL));
    if (numlevel == 0)
    {

        int nl = rand() % 13;
        int nr = rand() % 13;

        cout << nr << " " << nl;


        if (nl == 0) tex[0].loadFromFile("Pic/Level1/Q.png"), L = 'Q';
        else if (nl == 1) tex[0].loadFromFile("Pic/Level1/W.png"), L = 'W';
        else if (nl == 2) tex[0].loadFromFile("Pic/Level1/E.png"), L = 'E';
        else if (nl == 3) tex[0].loadFromFile("Pic/Level1/R.png"), L = 'R';
        else if (nl == 4) tex[0].loadFromFile("Pic/Level1/T.png"), L = 'T';
        else if (nl == 5) tex[0].loadFromFile("Pic/Level1/A.png"), L = 'A';
        else if (nl == 6) tex[0].loadFromFile("Pic/Level1/S.png"), L = 'S';
        else if (nl == 7) tex[0].loadFromFile("Pic/Level1/D.png"), L = 'D';
        else if (nl == 8) tex[0].loadFromFile("Pic/Level1/F.png"), L = 'F';
        else if (nl == 9) tex[0].loadFromFile("Pic/Level1/Z.png"), L = 'Z';
        else if (nl == 10) tex[0].loadFromFile("Pic/Level1/X.png"), L = 'X';
        else if (nl == 11) tex[0].loadFromFile("Pic/Level1/C.png"), L = 'C';
        else if (nl == 12) tex[0].loadFromFile("Pic/Level1/V.png"), L = 'V';

        if (nr == 0) tex[1].loadFromFile("Pic/Level1/Y.png"), R = 'Y';
        else if (nr == 1) tex[1].loadFromFile("Pic/Level1/U.png"), R = 'U';
        else if (nr == 2) tex[1].loadFromFile("Pic/Level1/I.png"), R = 'I';
        else if (nr == 3) tex[1].loadFromFile("Pic/Level1/O.png"), R = 'O';
        else if (nr == 4) tex[1].loadFromFile("Pic/Level1/P.png"), R = 'P';
        else if (nr == 5) tex[1].loadFromFile("Pic/Level1/G.png"), R = 'G';
        else if (nr == 6) tex[1].loadFromFile("Pic/Level1/H.png"), R = 'H';
        else if (nr == 7) tex[1].loadFromFile("Pic/Level1/J.png"), R = 'J';
        else if (nr == 8) tex[1].loadFromFile("Pic/Level1/K.png"), R = 'K';
        else if (nr == 9) tex[1].loadFromFile("Pic/Level1/L.png"), R = 'L';
        else if (nr == 10) tex[1].loadFromFile("Pic/Level1/B.png"), R = 'B';
        else if (nr == 11) tex[1].loadFromFile("Pic/Level1/N.png"), R = 'N';
        else if (nr == 12) tex[1].loadFromFile("Pic/Level1/M.png"), R = 'M';

        sprite[0].setTexture(tex[0]);
        sprite[0].setPosition(sf::Vector2f(-106, 307));
        sprite[1].setTexture(tex[1]);
        sprite[1].setPosition(sf::Vector2f(1152, 307));
        sprite[2].setTexture(tex[1]);
        sprite[2].setPosition(sf::Vector2f(1152, 307));





    }

    else if (numlevel == 1)
    {
        int nl = rand() % 9;
        int nr = rand() % 9;
        int nt = rand() % 8;
        cout << nr << " " << nl << " " << nt;
        if (nl == 0) tex[0].loadFromFile("Pic/Level2/Q.png"), L = 'Q';
        else if (nl == 1) tex[0].loadFromFile("Pic/Level2/W.png"), L = 'W';
        else if (nl == 2) tex[0].loadFromFile("Pic/Level2/E.png"), L = 'E';
        else if (nl == 3) tex[0].loadFromFile("Pic/Level2/A.png"), L = 'A';
        else if (nl == 4) tex[0].loadFromFile("Pic/Level2/S.png"), L = 'S';
        else if (nl == 5) tex[0].loadFromFile("Pic/Level2/D.png"), L = 'D';
        else if (nl == 6) tex[0].loadFromFile("Pic/Level2/Z.png"), L = 'Z';
        else if (nl == 7) tex[0].loadFromFile("Pic/Level2/X.png"), L = 'X';
        else if (nl == 8) tex[0].loadFromFile("Pic/Level2/C.png"), L = 'C';


        if (nr == 0) tex[1].loadFromFile("Pic/Level2/U.png"), R = 'U';
        else if (nr == 1) tex[1].loadFromFile("Pic/Level2/I.png"), R = 'I';
        else if (nr == 2) tex[1].loadFromFile("Pic/Level2/O.png"), R = 'O';
        else if (nr == 3) tex[1].loadFromFile("Pic/Level2/P.png"), R = 'P';
        else if (nr == 4) tex[1].loadFromFile("Pic/Level2/J.png"), R = 'J';
        else if (nr == 5) tex[1].loadFromFile("Pic/Level2/K.png"), R = 'K';
        else if (nr == 6) tex[1].loadFromFile("Pic/Level2/L.png"), R = 'L';
        else if (nr == 7) tex[1].loadFromFile("Pic/Level2/N.png"), R = 'N';
        else if (nr == 8) tex[1].loadFromFile("Pic/Level2/M.png"), R = 'M';

        if (nt == 0) tex[2].loadFromFile("Pic/Level2/R.png"), T = 'R';
        else if (nt == 1) tex[2].loadFromFile("Pic/Level2/T.png"), T = 'T';
        else if (nt == 2) tex[2].loadFromFile("Pic/Level2/Y.png"), T = 'Y';
        else if (nt == 3) tex[2].loadFromFile("Pic/Level2/F.png"), T = 'F';
        else if (nt == 4) tex[2].loadFromFile("Pic/Level2/G.png"), T = 'G';
        else if (nt == 5) tex[2].loadFromFile("Pic/Level2/H.png"), T = 'H';
        else if (nt == 6) tex[2].loadFromFile("Pic/Level2/V.png"), T = 'V';
        else if (nt == 7) tex[2].loadFromFile("Pic/Level2/B.png"), T = 'B';

        sprite[0].setTexture(tex[0]);
        sprite[0].setPosition(sf::Vector2f(-106, 307));
        sprite[1].setTexture(tex[1]);
        sprite[1].setPosition(sf::Vector2f(1152, 307));
        sprite[2].setTexture(tex[2]);
        sprite[2].setPosition(sf::Vector2f(523, -322));
    }

    else if (numlevel == 2)
    {
        int nl = rand() % 7;
        int nr = rand() % 6;
        int nt = rand() % 6;
        int nu = rand() % 7;

        if (nl == 0) tex[0].loadFromFile("Pic/Level3/Q.png"), L = 'Q';
        else if (nl == 1) tex[0].loadFromFile("Pic/Level3/W.png"), L = 'W';
        else if (nl == 2) tex[0].loadFromFile("Pic/Level3/A.png"), L = 'A';
        else if (nl == 3) tex[0].loadFromFile("Pic/Level3/S.png"), L = 'S';
        else if (nl == 4) tex[0].loadFromFile("Pic/Level3/D.png"), L = 'D';
        else if (nl == 5) tex[0].loadFromFile("Pic/Level3/Z.png"), L = 'Z';
        else if (nl == 6) tex[0].loadFromFile("Pic/Level3/X.png"), L = 'X';

        if (nr == 0) tex[1].loadFromFile("Pic/Level3/O.png"), R = 'O';
        else if (nr == 1) tex[1].loadFromFile("Pic/Level3/P.png"), R = 'P';
        else if (nr == 2) tex[1].loadFromFile("Pic/Level3/J.png"), R = 'J';
        else if (nr == 3) tex[1].loadFromFile("Pic/Level3/K.png"), R = 'K';
        else if (nr == 4) tex[1].loadFromFile("Pic/Level3/L.png"), R = 'L';
        else if (nr == 5) tex[1].loadFromFile("Pic/Level3/M.png"), R = 'M';

        if (nt == 0) tex[2].loadFromFile("Pic/Level3/E.png"), T = 'E';
        else if (nt == 1) tex[2].loadFromFile("Pic/Level3/R.png"), T = 'R';
        else if (nt == 2) tex[2].loadFromFile("Pic/Level3/T.png"), T = 'T';
        else if (nt == 3) tex[2].loadFromFile("Pic/Level3/Y.png"), T = 'Y';
        else if (nt == 4) tex[2].loadFromFile("Pic/Level3/U.png"), T = 'U';
        else if (nt == 5) tex[2].loadFromFile("Pic/Level3/I.png"), T = 'I';

        if (nu == 0) tex[3].loadFromFile("Pic/Level3/F.png"), U = 'F';
        else if (nu == 1) tex[3].loadFromFile("Pic/Level3/G.png"), U = 'G';
        else if (nu == 2) tex[3].loadFromFile("Pic/Level3/H.png"), U = 'H';
        else if (nu == 3) tex[3].loadFromFile("Pic/Level3/C.png"), U = 'C';
        else if (nu == 4) tex[3].loadFromFile("Pic/Level3/V.png"), U = 'V';
        else if (nu == 5) tex[3].loadFromFile("Pic/Level3/B.png"), U = 'B';
        else if (nu == 6) tex[3].loadFromFile("Pic/Level3/N.png"), U = 'N';


        sprite[0].setTexture(tex[0]);
        sprite[0].setPosition(sf::Vector2f(-106, 307));
        sprite[1].setTexture(tex[1]);
        sprite[1].setPosition(sf::Vector2f(1152, 307));
        sprite[2].setTexture(tex[2]);
        sprite[2].setPosition(sf::Vector2f(523, -322));
        sprite[3].setTexture(tex[3]);
        sprite[3].setPosition(sf::Vector2f(523, 936));

    }
    FILE* fp;
    char time1[1000];
    fp = fopen("song0.txt", "r+t");
    if (numsong == 0) fp = fopen("tack/song0.txt", "r+t");
    else if (numsong == 1) fp = fopen("tack/song1.txt", "r+t");
    else if (numsong == 2) fp = fopen("tack/song2.txt", "r+t");
    else if (numsong == 3) fp = fopen("tack/song3.txt", "r+t");
    else if (numsong == 4) fp = fopen("tack/song4.txt", "r+t");
    else if (numsong == 5) fp = fopen("tack/song5.txt", "r+t");
    else if (numsong == 6) fp = fopen("tack/song6.txt", "r+t");
    else if (numsong == 7) fp = fopen("tack/song7.txt", "r+t");
    else if (numsong == 8) fp = fopen("tack/song8.txt", "r+t");
    else if (numsong == 9) fp = fopen("tack/song9.txt", "r+t");

    int n = 0;

    while (!feof(fp))
    {
        int num = 0;
        fgets(time1, 100, fp);

        for (int i = 0; i < strlen(time1) - 1; i++)
        {
            num = (num * 10) + time1[i] - 48;
        }

        if (n % (numlevel + 2) == 0)
        {

            vec.push_back(make_pair(make_pair(num, sprite[0]), 0));
        }

        if (n % (numlevel + 2) == 1)
        {
            vec.push_back(make_pair(make_pair(num, sprite[1]), 1));
        }

        if (n % (numlevel + 2) == 2)
        {
            vec.push_back(make_pair(make_pair(num, sprite[2]), 2));
        }

        if (n % (numlevel + 2) == 3)
        {
            vec.push_back(make_pair(make_pair(num, sprite[3]), 3));
        }
        n++;
    }
    fclose(fp);

    if (!vec.empty()) vec.pop_back();
}
