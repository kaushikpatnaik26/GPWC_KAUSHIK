while(window.isOpen()){
    Event event;
    while(window.pollEvent(event))
    {
        if(event.type = closed || (event.type = event.keypressed::keyboard 
            && event.key.code == keyboard::Escape))
            {
                window.close();
            }
        window.clear();
        window.display();
        
    }
}