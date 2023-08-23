//#include "Header.h"

#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::Image app_icon;
    app_icon.loadFromFile("include/icons/hackeado.png");
    sf::RenderWindow main(sf::VideoMode(250, 350), "Hardware Serial Spoofer", sf::Style::Close | sf::Style::Titlebar);
    main.setIcon(app_icon.getSize().x, app_icon.getSize().y, app_icon.getPixelsPtr());
    main.setFramerateLimit(60);

    sf::Cursor cursor_hand, cursor_default;

    sf::Texture githubiconT, discordiconT;

    sf::Font montserrat_r, montserrat_b;
    sf::Text welcome_message, warning_disclaimer; //what more can i enter in draw(), why cant define multiples 

    sf::RectangleShape mediabar, spoofmac_buttn;

    sf::Vertex mediaseparator[] = {
        sf::Vertex(sf::Vector2f(0, static_cast<float>(main.getSize().y) - 45)),
        sf::Vertex(sf::Vector2f(static_cast<float>(main.getSize().x), static_cast<float>(main.getSize().y) - 45))
    };
    mediaseparator[0].color = sf::Color(138, 138, 138);
    mediaseparator[1].color = sf::Color(138, 138, 138);
    
    if(!cursor_hand.loadFromSystem(sf::Cursor::Hand)) {
        return -1;
    }

    if(!cursor_default.loadFromSystem(sf::Cursor::Arrow)) {
        return -1;
    }

    if(!githubiconT.loadFromFile("include/icons/github.png")) {
        return -1;
    }

    if(!discordiconT.loadFromFile("include/icons/discord.png")) {
        return -1;
    }

    if(!montserrat_r.loadFromFile("include/fonts/montr.ttf")) {
        return -1;
        
    }

    if(!montserrat_b.loadFromFile("include/fonts/montb.ttf")) {
        return -1;
    }

    sf::Sprite github_icon(githubiconT);
    github_icon.setScale(0.06f, 0.06f);
    github_icon.setOrigin(githubiconT.getSize().x, githubiconT.getSize().y);
    github_icon.setPosition(main.getSize().x, main.getSize().y);

    sf::Sprite discord_icon(discordiconT);
    discord_icon.setScale(0.012f, 0.012f);
    discord_icon.setOrigin(discordiconT.getSize().x, discordiconT.getSize().y);
    discord_icon.setPosition(main.getSize().x - 38.0f, main.getSize().y + 3);

    welcome_message.setFont(montserrat_b);
    welcome_message.setCharacterSize(18);
    welcome_message.setString("Author: @ferrnnaando");
    welcome_message.setFillColor(sf::Color::Black);
    welcome_message.setPosition(20, 20);

    warning_disclaimer.setFont(montserrat_r);
    warning_disclaimer.setCharacterSize(8);
    warning_disclaimer.setString("Disclaimer: Be discret using this, @ferrnnaando\nand her real entity creator is not responsable\n   of any illegal use that can be given to this\n         program. Just for ethical learning.");
    warning_disclaimer.setFillColor(sf::Color::Black);
    warning_disclaimer.setPosition(main.getSize().x / 11, 40);
    warning_disclaimer.setStyle(sf::Text::Italic);

    mediabar.setSize(sf::Vector2f((float)main.getSize().x, 45));
    mediabar.setPosition(sf::Vector2f(0, (float)main.getSize().y - mediabar.getSize().y));
    mediabar.setFillColor(sf::Color(217, 217, 217));

    spoofmac_buttn.setSize(sf::Vector2f((float)main.getSize().x / 2, 35));
    spoofmac_buttn.setPosition(sf::Vector2f((float)main.getSize().x / 5, (float)main.getSize().y / 2));
    spoofmac_buttn.setFillColor(sf::Color(227, 227, 227));

    while(main.isOpen()) {  
        sf::Event main_event;
        while(main.pollEvent(main_event)) {
            if(main_event.type == sf::Event::Closed) {
                //system("open https://github.es/ferrnnaando/");
                main.close();
            }

            sf::Vector2i mousePos = sf::Mouse::getPosition(main);
            if(github_icon.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                main.setMouseCursor(cursor_hand);

                if(main_event.type == sf::Event::MouseButtonPressed ) {
                    if(github_icon.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        std::system("open https://github.com/ferrnnaando/");
                    }
                }
            } else {
                main.setMouseCursor(cursor_default);
            }
        }

        main.clear(sf::Color(242, 242, 242));
        main.draw(welcome_message);
        main.draw(warning_disclaimer);
        main.draw(spoofmac_buttn);

        main.draw(mediabar);
        main.draw(github_icon);
        main.draw(discord_icon);
        main.draw(mediaseparator, 2, sf::Lines);
        main.display();
    }

    return 0;
}
