Texture texture;
texture.loadfilefrom("Soa.png");
Sprite sprite;
sprite.setTexture(texture);

RenderWindow window(VideoMode(960,540), "Soa Logo");
while(window.isOpen())
{
    Event event;
    while(window.pollEvent(event))
    {
        if(event.type = event::closed())
        {
            window.close();
        }
        window.clear();
        window.draw(sprite);
        window.display();   
    }
}