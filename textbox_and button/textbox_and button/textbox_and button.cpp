#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Textbox.h"
#include "Button.h"

int main() {
	sf::RenderWindow window;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

	window.create(sf::VideoMode(900, 900), "SFML Textbox", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

		sf::Font font;
		if (!font.loadFromFile("ShortStack-Regular.otf"))
			std::cout << "Font not found!\n";

		Textbox text1(20, sf::Color::White, true);
		text1.setPosition({ 100, 100 });
		text1.setLimit(true, 30);
		text1.setFont(font);

		sf::Vector2f btn1_ps(200, 100);
		Button btn1("Enter", { btn1_ps }, 30, sf::Color::Green, sf::Color::Black);
		btn1.setFont(font);
		btn1.setPosition({ 100, 300 });
		Button btn();

		Button btn2("Exit", { 200, 50 }, 30, sf::Color::Blue, sf::Color::Black);
		btn2.setFont(font);
		btn2.setPosition({ 100, 10 });

		Button btn3("New", { 200, 50 }, 30, sf::Color::Blue, sf::Color::Black);
		btn3.setFont(font);
		btn3.setPosition({ 200, 20 });

	//Main Loop:
	while (window.isOpen()) {

		sf::Event Event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			text1.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			text1.setSelected(false);
		}

		//Event Loop:
		while (window.pollEvent(Event)) {
			switch (Event.type) {

			case sf::Event::Closed:
				window.close();
			case sf::Event::TextEntered:
				text1.typedOn(Event);
			case sf::Event::MouseMoved:
				if (btn1.isMouseOver(window)) {
					btn1.setBackColor(sf::Color::Magenta);
				}
				else {
					btn1.setBackColor(sf::Color::Green);
				}
				if (btn2.isMouseOver(window)) {
					btn2.setBackColor(sf::Color::Magenta);
				}
				else {
					btn2.setBackColor(sf::Color::Blue);
				}

				if (btn3.isMouseOver(window)) {
					btn3.setBackColor(sf::Color::Magenta);
				}
				else {
					btn3.setBackColor(sf::Color::Blue);
				}

				break;
			case sf::Event::MouseButtonPressed:
				if (btn1.isMouseOver(window)) {
					std::cout << "Hello " << text1.getText() << "\n";
					std::string s = text1.getText();
					
					std::cout << s << std::endl;
				}
				if (btn2.isMouseOver(window))
				{
					std::cout << "Exit" << std::endl;
							

				}
			}
		}
		window.clear();
		text1.drawTo(window);
		
		btn1.drawTo(window);
		btn2.drawTo(window);
		
		window.display();
	}
	return 0;
}