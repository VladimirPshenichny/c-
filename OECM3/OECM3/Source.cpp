#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>

#define PI 3.14f
using namespace sf;

float Function(float argument) {
    return float((pow(sin(argument / 4), 3) + sqrt(argument)) * -1 + 10.f);
}

int main() {

    int size = 0;
    sf::Font font;

    sf::Text text;
    text.setFont(font);
    text.setScale(sf::Vector2f(0.01f, 0.01f));
    text.setFillColor(sf::Color::White);

    sf::RenderWindow window(sf::VideoMode(1280, 1024), "He znay");
    window.setFramerateLimit(30);
    sf::Vertex Xaxis[] = {
        sf::Vertex(sf::Vector2f(0.f, 10.f)),
        sf::Vertex(sf::Vector2f(35.f, 10.f))
    };

    sf::View myView(sf::Vector2f(24, 10), sf::Vector2f(50, 20));
    window.setView(myView);

    VertexArray LinesY(Lines, 2); //
    LinesY[0].position = Vector2f(0, 0);
    LinesY[0].color = Color::White;
    LinesY[1].position = Vector2f(0, 20);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed) window.close();

        window.clear();
        for (float i = 3 * PI / 2; i < 16 * PI; i += 0.05f) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(i, Function(i))),
                sf::Vertex(sf::Vector2f(i + 0.1f, Function(i + 0.1f)))
            };
            window.draw(line, 2, sf::Lines);
        }
        for (float i = 1.f; i < 28.f; i++) {
            text.setString(std::to_string(int(i)));
            text.setPosition(sf::Vector2f(i, 10.f));
            window.draw(text);
        }
        for (float i = 4.f; i > -5.f; i--) {
            text.setString(std::to_string(int(-i)));
            text.setPosition(sf::Vector2f(0.1f, i + 10.f));
            window.draw(text);
        }
        VertexArray line(Lines, 2);
        line[0].position = Vector2f(0, 0);
        line[0].color = Color::White;
        line[1].position = Vector2f(100, 0);
        text.setString("Biggest value: 1");
        text.setPosition(sf::Vector2f(10.f, 15.f));
        window.draw(text);
        window.draw(Xaxis, 2, sf::Lines);
        window.draw(LinesY);
        window.display();
    }

    return 0;
}