#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // 1. Configure settings for smooth, anti-aliased tree rendering
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // 2. Create the window setup (matching a standard 720p level canvas layout)
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Working Test - Vault Heist Setup", sf::Style::Default, settings);
    window.setFramerateLimit(60); // Guarantees a stable 60 FPS cap for animations

    // 3. Create a placeholder vault node (Green circle indicating a balanced tree state)
    sf::CircleShape nodeShape(40.f); 
    nodeShape.setFillColor(sf::Color(46, 204, 113)); // Safe green matching game palette
    nodeShape.setOutlineThickness(4.f);
    nodeShape.setOutlineColor(sf::Color::White);
    
    // Center the node in the window
    nodeShape.setOrigin(40.f, 40.f);
    nodeShape.setPosition(1280 / 2.f, 720 / 2.f);

    // 4. Set up text rendering to verify font engine working
    sf::Font font;
    // Standard system font location on Ubuntu Linux distributions
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        std::cout << "Warning: Could not load default Ubuntu font. Text will not render, but window will function.\n";
    }

    sf::Text text("SFML IS WORKING", font, 24);
    text.setFillColor(sf::Color::White);
    // Center text below the node
    text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);
    text.setPosition(1280 / 2.f, (720 / 2.f) + 80.f);

    std::cout << "Initialization successful. Opening window...\n";

    // 5. Main Game Loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Process close event or Escape key press
            if (event.type == sf::Event::Closed || 
               (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        // 6. Draw Cycle
        window.clear(sf::Color(20, 20, 25)); // Dark vault asset background color
        
        window.draw(nodeShape);
        window.draw(text);
        
        window.display();
    }

    return 0;
}
