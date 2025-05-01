

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

using namespace sf;

int main() {
    // create a video mode object
    VideoMode vm(1920, 1080);
    // to create and open a window 
    RenderWindow window(vm, "Timber", Style::Fullscreen);

    // create an object that will hold a graphics on gpu
    Texture textureBackground; 
    
    // load graphics in the texture
    textureBackground.loadFromFile("../graphics/background.png");
    
    // Create a sprite
    Sprite spriteBackground;
    
    // attach texture to sprite
    spriteBackground.setTexture(textureBackground);
    
    // set the spritebackground position to cover the screen
    spriteBackground.setPosition(0, 0);
    
    // make a tree sprite
    Texture textureTree;
    textureTree.loadFromFile("../graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);
    
    // adding bee in the spritesheet
    Texture textureBee;
    textureBee.loadFromFile("../graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(2000, 800);
    
    // is the bee currently moving
    bool beeActive = false;
    
    // how fast the bee can fly
    float beeSpeed = 0.0f;
    
    // make 3 cloud sprites in 1 texture
    Texture textureCloud;
    
    // load 1 new texture
    textureCloud.loadFromFile("../graphics/cloud.png");
    
    // 3 new sprites with the same texture
    Sprite spriteCloud1, spriteCloud2, spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    
    
    // position of cloud at left side of screen at different position
    spriteCloud1.setPosition(-200, 0);
    spriteCloud2.setPosition(-300, 250);
  
    
    // are the clouds currently moving
    bool cloud1Active = false, cloud2Active = false, cloud3Active = false;
    
    // how fast the cloud should be moving
    float cloud1Speed = 0.0f, cloud2Speed = 0.0f, cloud3Speed = 0.0f;

    // Clock to track time
    Clock clock;
    srand(static_cast<unsigned>(time(0)));
    
    while (window.isOpen()) {
        /* Handle the player input */
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        /* Update the scene */
        Time dt = clock.restart();

        // Manage the bee movement
        if (!beeActive) {
            beeSpeed = (rand() % 200) + 200; // Random speed between 200 - 400
            float height = (rand() % 500) + 500; // Random height between 500 - 1000
            spriteBee.setPosition(2000, height);
            beeActive = true;
        } else {
            spriteBee.move(-beeSpeed * dt.asSeconds(), 0);
            if (spriteBee.getPosition().x < -100) {
                beeActive = false;
            }
        }

        // Manage cloud 1 movement
        if (!cloud1Active) {
            cloud1Speed = (rand() % 100) + 100;
            spriteCloud1.setPosition(-200, (rand() % 150));
            cloud1Active = true;
        } else {
            spriteCloud1.move(cloud1Speed * dt.asSeconds(), 0);
            if (spriteCloud1.getPosition().x > 1920) {
                cloud1Active = false;
            }
        }

        // Manage cloud 2 movement
        if (!cloud2Active) {
            cloud2Speed = (rand() % 150) + 100;
            spriteCloud2.setPosition(-300, (rand() % 200) + 200);
            cloud2Active = true;
        } else {
            spriteCloud2.move(cloud2Speed * dt.asSeconds(), 0);
            if (spriteCloud2.getPosition().x > 1920) {
                cloud2Active = false;
            }
        }

                window.clear();
        window.draw(spriteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.display();
    }
    
    return 0;
}
