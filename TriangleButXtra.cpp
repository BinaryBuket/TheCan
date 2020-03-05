#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <cmath>
using namespace sf;
using namespace std;

bool isRightTriangle(vector<int> corrdinates){
    """Finds if triangle is right""";
    int ax = corrdinates[0];
    int ay = corrdinates[1];

    int bx = corrdinates[2];
    int by = corrdinates[3];

    int cx = corrdinates[4];
    int cy = corrdinates[5];

    int RedBlue = pow(bx - ax, 2) + pow(by - ay, 2);
    int BlueGreen = pow(cx - bx, 2) + pow(cy - by, 2);
    int RedGreen = pow(cx - ax, 2) + pow(cy - ay, 2);

    int ans;

    if (RedBlue > BlueGreen && RedBlue > RedGreen){
        ans = BlueGreen + RedGreen;
        if (ans == RedBlue)
            return true;
    }else if (BlueGreen > RedGreen){
        ans = RedBlue + RedGreen;
        if (ans == BlueGreen)
            return true;
    }else{
        ans = RedBlue + BlueGreen;
        if (ans == RedGreen)
            return true;
    }

    return false;
}

double mathTime(vector<int> corrdinates){
    """Finds area of the triangle""";
    double area;
    double firstSec;
    double secondSec;
    double thirdSec;
    double a = corrdinates[0];
    double b = corrdinates[1];
    double c = corrdinates[2];
    double d = corrdinates[3];
    double e = corrdinates[4];
    double f = corrdinates[5];

    firstSec = a * (d - f);
    secondSec = c * (f - b);
    thirdSec = e * (b - d);
    area = (firstSec + secondSec + thirdSec) / 2;

    return abs(area);
}

 VertexArray makeTriangle(vector<int> &corrdinates){
    """Make triangle""";
    int x,y;
    srand((int)time(NULL));
    VertexArray triangle(Triangles, 3);

    for (int i = 0; i < 6; i++){
        x = rand() % 400 + 400; // take less than half of the
        y = rand() % 400; // window for a line in middle
        corrdinates.push_back(x);
        corrdinates.push_back(y);
        // need the array to find the area later
    }

    triangle[0].position = Vector2f(corrdinates[0], corrdinates[1]);
    triangle[1].position = Vector2f(corrdinates[2], corrdinates[3]);
    triangle[2].position = Vector2f(corrdinates[4], corrdinates[5]);

    triangle[0].color = Color::Red;
    triangle[1].color = Color::Blue;
    triangle[2].color = Color::Green;

    cout << corrdinates[0] << "," << corrdinates[1] << " " << "Red" << endl;
    cout << corrdinates[2] << "," << corrdinates[3] << " " << "Blue" << endl;
    cout << corrdinates[4] << "," << corrdinates[5] << " " << "Green" << endl;

    cout << endl;

    return triangle;
}

VertexArray middleLine(){
    // line to separate the triangle and the rectangle
    VertexArray midLine(Lines, 2);

    midLine[0].position = Vector2f(401.f, 0.f);
    midLine[1].position = Vector2f(401.f, 400.f);

    return midLine;
}

int main(){
    int again = 1;
    bool rightTriangle;
    double triarea;
    double sides4Rect;
    vector<int> corrdinates;
    VertexArray tri(Triangles, 3);
    VertexArray line(Lines, 2);
    RectangleShape rect(Vector2f(0,0));

    ContextSettings settings;
    settings.antialiasingLevel = 6;

    RenderWindow window(VideoMode(802,400), "Triangle!", Style::Default, settings);
    while (window.isOpen()){
        Event event;

        line = middleLine();

        cin >> again;
        if (again >= 0){
            corrdinates.clear();

            tri = makeTriangle(corrdinates);
            rightTriangle = isRightTriangle(corrdinates);
            triarea = mathTime(corrdinates);
            // area of rect is down there 
            sides4Rect = sqrt(triarea);
            rect.setSize(Vector2f(sides4Rect,sides4Rect));
            rect.setFillColor(Color::Green);

            cout << "AREA: " << triarea << endl;
            cout << "RIGHT: " << rightTriangle << endl;

            again = -1;
        }

        while (window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(line);
        window.draw(tri);
        window.draw(rect);
        window.display();
    }
    return 0;
}
