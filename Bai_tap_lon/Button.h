#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
private:
	sf::RectangleShape button;
	sf::Text text;

	int btnWidth;
	int btnHeight;

public:
	Button() {
		sf::Vector2f vector;
		vector.x = 0;
		vector.y = 0;
		button.setSize(vector);
		button.setFillColor(sf::Color::White);
		btnHeight = 0;
		btnHeight = 0;

		text.setString("");
		text.setCharacterSize(0);
		text.setFillColor(sf::Color::White);
	}

	~Button() {

	}
	Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor) {
		button.setSize(buttonSize);
		button.setFillColor(bgColor);

		// Get these for later use:
		btnWidth = buttonSize.x;
		btnHeight = buttonSize.y;

		text.setString(btnText);
		text.setCharacterSize(charSize);
		text.setFillColor(textColor);
	}

	void setButton(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor) {
		button.setFillColor(bgColor);
		button.setSize(buttonSize);
		
		// Get these for later use:
		btnWidth = buttonSize.x;
		btnHeight = buttonSize.y;

		text.setString(btnText);
		text.setCharacterSize(charSize);
		text.setFillColor(textColor);
	}

	void setString(std::string btntext) {
		text.setString(btntext);
	}
	void setButtonSize(sf::Vector2f btnSize) {
		btnWidth = btnSize.x;
		btnHeight = btnSize.y;
	}
	void setCharSize(int chrSize) {
		text.setCharacterSize(chrSize);
	}

	// Pass font by reference:
	void setFont(sf::Font& fonts) {
		text.setFont(fonts);
	}

	void setBackColor(sf::Color color) {
		button.setFillColor(color);
	}

	void setTextColor(sf::Color color) {
		text.setFillColor(color);
	}

	void setPosition(sf::Vector2f point) {
		button.setPosition(point);

		// Center text on button:
		float xPos = (point.x + btnWidth / 2) - (text.getLocalBounds().width / 2);
		float yPos = (point.y + btnHeight / 2.2) - (text.getLocalBounds().height / 2);
		text.setPosition(xPos, yPos);
	}

	void drawTo(sf::RenderWindow& window) {
		window.draw(button);
		window.draw(text);
	}

	// Check if the mouse is within the bounds of the button:
	bool isMouseOver(sf::RenderWindow& window) {
		int mouseX = sf::Mouse::getPosition(window).x;
		int mouseY = sf::Mouse::getPosition(window).y;

		int btnPosX = button.getPosition().x;
		int btnPosY = button.getPosition().y;

		int btnxPosWidth = button.getPosition().x + btnWidth;
		int btnyPosHeight = button.getPosition().y + btnHeight;

		if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
			return true;
		}
		return false;
	}
	void reset() {
		button.setFillColor(sf::Color::Transparent);
		sf::Vector2f vector;
		vector.x = 0;
		vector.y = 0;
		button.setSize(vector);

		// Get these for later use:
		btnWidth = 0;
		btnHeight = 0;

		text.setString("");
		text.setCharacterSize(0);
		text.setFillColor(sf::Color::Transparent);
	}
};
