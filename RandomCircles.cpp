#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace sf;
using namespace std;
CircleShape makeCircles(){
    int x,y, r,g,b;

    x = rand() % 800;
    y = rand() % 600;

    r = rand() % 255;
    g = rand() % 255;
    b = rand() % 255;

    CircleShape shape(rand() % 150);
    shape.setPosition(x,y);
    shape.setFillColor(Color(r,g,b));

    return shape;
}

int main(){
    int amount = -1;
    int x,y, r,g,b;

    RenderWindow window(VideoMode(800,600), "Random circles!");
    srand((int)time(NULL));

    cout << "How many circles would you like: ";
    cin >> amount;

    if (amount > 0){
        vector<CircleShape> circles;
        // this is here so array isn't -1 size or something
        for (int i = 0; i < amount; i++){
            circles.push_back(makeCircles());
            // puts returned circle into the circle shape vector
        }

        while (window.isOpen()){
            Event event;

            while (window.pollEvent(event)){
                if(event.type == Event::Closed){
                    window.close();
                }
            }
            window.clear();
            for (int a = 0; a < amount; a++){
                window.draw(circles[a]);
            }
            window.display();
        }
    }
    return 0;
}
