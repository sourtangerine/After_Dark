#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "After Dark");

    // Load sprite
    sf::Texture texture;
    if (!texture.loadFromFile("assets/sprite/enemy1.png"))
    {
        std::cerr << "Failed to load enemy1.png" << std::endl;
        return 1;
    }
    sf::Sprite sprite(texture);

    // Load music
    sf::Music music;
    if (!music.openFromFile("assets/music/alex_besss-a-dramatic-war-film-score-402028.mp3"))
    {
        std::cerr << "Failed to load music" << std::endl;
        return 1;
    }
    music.play();

    // Start the game loop
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
