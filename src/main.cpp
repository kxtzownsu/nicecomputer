#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {
    const char* videoFilePath = "nicecomputer.mp4";

    // Create a window
    sf::RenderWindow window(sf::VideoMode(640, 480), "Video Player");

    // Create a video texture
    sf::Texture videoTexture;
    if (!videoTexture.loadFromFile(videoFilePath)) {
        // Handle error loading video
        return 1;
    }

    // Create a sprite to display the video
    sf::Sprite videoSprite(videoTexture);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window
        window.clear();

        // Draw the video sprite
        window.draw(videoSprite);

        // Display the contents of the window
        window.display();
    }

    return 0;
}

