#pragma once

#include <SFML/Window/Mouse.hpp>

#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>


using namespace sf;
using namespace std;
sf::RenderWindow window(sf::VideoMode(1200, 640), "Librarian", sf::Style::Titlebar | sf::Style::Close | Style::Resize);

void inputText(float x ,float y) {
	
	sf::Font arial;
	if (!arial.loadFromFile("DejaVuSansMono.ttf")) {
		cout << "cant load file" << endl;
	}
	sf::Text t;
	t.setFillColor(sf::Color::Black);
	t.setFont(arial);
	std::string s = "";
	t.setString(s);
	t.setPosition(x,y);

	
		sf::Event event;

		while (window.pollEvent(event)) {
			
			if (event.type == sf::Event::TextEntered) {

				if (event.text.unicode < 128) {
					s += static_cast<char>(event.text.unicode);
				}
				else {
					// Time to consider sf::String or some other unicode-capable string

					s.append(std::to_string(event.key.code));
				}

			}

		}

		t.setString(s);
		
		window.draw(t);
	
	
}