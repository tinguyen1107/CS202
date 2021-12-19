#ifndef TextField_h
#define TextField_h

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;

class TextField {
public:
    TextField(int size, sf::Color color, bool sel) {
        tf.setCharacterSize(size);
        tf.setFillColor(color);
        isSelected = sel;

        limit = size;

        if (sel) {
            this->tf.setString("_");
        }
        else {
            this->tf.setString("");
        }
    }

    void setFont(sf::Font& font) {
        tf.setFont(font);
    }

    void setPosition(sf::Vector2f pos) {
        tf.setPosition(pos);
    }

    void setLimit(bool _hasLimit, int _limit = -1) {
        this->hasLimit = _hasLimit;
        if (_limit != -1) this->limit = _limit;
    }

    void setSelected(bool _sel) {
        this->isSelected = _sel;

        if (!_sel) {
            this->deleteLastChar();
        }
    }

    string getText() { return this->text.str(); }

    void drawTo(sf::RenderWindow& window) {
        window.draw(tf);
    }

    void typeOn(sf::Event event) {
        if (this->isSelected) {
            int charType = event.text.unicode;
            if (charType < 128) {
                if (hasLimit) {
                    if (text.str().length() <= limit) {
                        inputLogic(event);
                    }
                }
            }
        }
    }

    int inputLogic(sf::Event event) {
        switch (event.type) {
        case sf::Event::KeyPressed:
            switch (event.key.code) {
            case sf::Keyboard::Enter:
                this->isSelected = !this->isSelected;
                break;
            case sf::Keyboard::Delete:
                this->deleteLastChar();
                break;
            default:
                int charTyped = event.text.unicode;
                if (charTyped < 26) {
                    charTyped += 97;
                    std::cout << "FIXED: " << static_cast<char>(charTyped) << std::endl;
                }
               /* else if () {

                }*/
                else {
                    std::cout << "ASCII character typed: " << charTyped << static_cast<char>(charTyped) << std::endl;
                }
               
                text << static_cast<char>(charTyped);
            }
        default:
            break;
        }

        tf.setString(text.str() + "_");
    }

private:
    sf::Text tf;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;

   /* int inputLogic(sf::Event event, sf::RenderWindow& window) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
            switch (event.key.code) {
            case sf::Keyboard::Enter:
                this->isSelected = !this->isSelected;
            case sf::Keyboard::Delete:
                this->deleteLastChar();
            default:
                cout << event.key.code << endl;
            }
		default:
			break;
		}

        tf.setString(text.str() + "_");
    }*/

    void deleteLastChar() {
        string t = text.str();
        string newText = "";

        for (int i = 0; i < t.length() - 1; ++i)
            newText += t[i];
        text.str("");
        text << newText;

        tf.setString(text.str());
    }
};

#endif