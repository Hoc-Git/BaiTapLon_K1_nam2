//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <SFML/Window/Mouse.hpp>
//#include <string>
#include "inputext.h"
using namespace std;
using namespace sf;

//sf::RenderWindow window(sf::VideoMode(1200, 640), "Librarian", sf::Style::Titlebar | sf::Style::Close | Style::Resize);

int k, se, tol;

void toltext(string in, float x, float y) {
    sf::Text sea;
    sf::Font font2;
    if (!font2.loadFromFile("UbuntuMono-B.ttf")) {
        cout << "Err" << endl;
    }
    sea.setFont(font2);
    sea.setString(in);//Tim kiem
    sea.setFillColor(Color::Black);
    sea.setPosition(x, y);
    sea.setCharacterSize(20);
    window.draw(sea);
}

void drw() {
    sf::Font font;
    if (!font.loadFromFile("Herrmes.ttf")) {
        cout << "Err" << endl;
    }

    sf::Text text;
    text.setFont(font);
    std::string s = "Toll";
    text.setString(s);
   text.setFillColor(Color::Blue);  
   //text.setColor(Color(255, 255, 255, 128));
    text.setPosition(10.f, 10.f);
    text.setCharacterSize(30);

    sf::Font font2;
    if (!font2.loadFromFile("UbuntuMono-B.ttf")) {
        cout << "Err" << endl;
    }
    sf::Text imp;
    imp.setFont(font2);
    imp.setString("Import");
    imp.setFillColor(Color::Black);
    imp.setPosition(250.f, 20.f);
    imp.setCharacterSize(20);

    sf::Text add;
    add.setFont(font2);
    add.setString("Add");
    add.setFillColor(Color::Black);
    add.setPosition(350.f, 20.f);
    add.setCharacterSize(20);

    sf::Text del;
    del.setFont(font2);
    del.setString("Delete");
    del.setFillColor(Color::Black);
    del.setPosition(450.f, 20.f);
    del.setCharacterSize(20);

    sf::Text gete;
    gete.setFont(font2);
    gete.setString("See top ");
    gete.setFillColor(Color::Black);
    gete.setPosition(550.f, 20.f);
    gete.setCharacterSize(20);

    sf::Text Sta;
    Sta.setFont(font2);
    Sta.setString("Statistical");//thong ke
    Sta.setFillColor(Color::Black);
    Sta.setPosition(650.f, 20.f);
    Sta.setCharacterSize(20);

    sf::Text sort;
    sort.setFont(font2);
    sort.setString("Sort");//sap xep
    sort.setFillColor(Color::Black);
    sort.setPosition(800.f, 20.f);
    sort.setCharacterSize(20);

    sf::Text sea;
    sea.setFont(font2);
    sea.setString("Search");//Tim kiem
    sea.setFillColor(Color::Black);
    sea.setPosition(900.f, 20.f);
    sea.setCharacterSize(20);

    window.draw(text);
    window.draw(imp);
    window.draw(add);
    window.draw(del);
    window.draw(gete);
    window.draw(Sta);
    window.draw(sort);
    window.draw(sea);
}
void textinput() {
    sf::Font font2;
    if (!font2.loadFromFile("UbuntuMono-B.ttf")) {
        cout << "Err" << endl;
    }
    sf::Text sea;
    string in="text here!";
   // getline(cin, in);
    sea.setFont(font2);
    sea.setString(in);//Tim kiem
    sea.setFillColor(Color::Black);
    sea.setPosition(900.f, 200.f);
    sea.setCharacterSize(20);
    window.draw(sea);
}
void search() {
    Texture pic;
   
    if (!pic.loadFromFile("search.png"))
    {
        cout << "Can't load img" << endl;
    }
    Sprite search;
    search.setTexture(pic);
    search.setPosition(Vector2f(970, 20));
    //racc.scale(Vector2f(0, ));
    window.draw(search);
}

void search1() {
    Texture pic;
    if (!pic.loadFromFile("search1.png"))
    {
        cout << "Can't load img 1" << endl;
    }
    Sprite search;
    search.setTexture(pic);
    search.setPosition(Vector2f(970, 20));
  
    window.draw(search);
}

void seach() {
    Texture pic;
    if (!pic.loadFromFile("search.png"))
    {
        cout << "Can't load img" << endl;
    }
    Sprite search;
    search.setTexture(pic);
    search.setPosition(Vector2f(970, 20));
    //racc.scale(Vector2f(0, ));
    window.draw(search);
}
void ap(){
    Texture ap;
    if (!ap.loadFromFile("app.png"))
    {
        cout << "Can't load img app" << endl;
    }
    Sprite app;
    app.setTexture(ap);
    app.setPosition(Vector2f(100, 200));
    app.setScale(0.5, 0.5);
    window.draw(app);
}
void backgr() {
    Texture pic;
    if (!pic.loadFromFile("background.png"))
    {
        cout << "Can't load img" << endl;
    }
    Sprite racc;
    racc.setTexture(pic);
    racc.setPosition(Vector2f(0, 0));

    window.draw(racc);
    seach();
    drw();
}
void namebar(float x, float y) {
    Texture pic;
    if (!pic.loadFromFile("namebar.png"))
    {
        cout << "Can't load img name bar" << endl;
    }
    Sprite racc;
    racc.setTexture(pic);
    racc.setPosition(Vector2f(x, y));

    window.draw(racc);

}
void soluongbar(float x, float y) {
    Texture pic;
    if (!pic.loadFromFile("soluong.png"))
    {
        cout << "Can't load img so luong bar" << endl;
    }
    Sprite racc;
    racc.setTexture(pic);
    racc.setPosition(Vector2f(x, y));

    window.draw(racc);

}
void sachbar(float x, float y) {
    Texture pic;
    if (!pic.loadFromFile("sach.png"))
    {
        cout << "Can't load img sach bar" << endl;
    }
    Sprite racc;
    racc.setTexture(pic);
    racc.setPosition(Vector2f(x, y));

    window.draw(racc);
}
void tableinbackgr() {
    Texture pic;
    if (!pic.loadFromFile("tablebackgr.png"))
    {
        cout << "Can't load img table" << endl;
    }
    Sprite racc;
    racc.setTexture(pic);
    racc.setPosition(Vector2f(100, 80));

    window.draw(racc);
  
}
void tool(int tol) {

    switch (tol) {
    case 1:
        cout << "case import." << endl;
        toltext("Import", 100, 100);
        tableinbackgr();
        break;
    case 2:
        //add
        cout << "case add" << endl;
        toltext("ADD", 200, 100);
        break;
    case 3:
        //delete
        toltext("Delete", 300, 100);
        break;
    case 4:
        toltext("See top", 400, 100);
        //see top
        break;
    case 5:
        toltext("statistical", 500, 100);
        //statistical
        break;
    case 6:
        cout << "sort case" << endl;
        toltext("Sort ", 600, 100);
        //sort
        break;

    }
}
void inputtext(int uni,Text &t, string &s) {
    cout << "Input text" << endl;
    sf::Font arial;
    if (!arial.loadFromFile("DejaVuSansMono.ttf")) {
        cout << "cant load file" << endl;
    }
    
    t.setFillColor(sf::Color::Black);
    t.setFont(arial);
   
    t.setString(s);
    t.setPosition(300, 400);
    if (uni < 128) {
        s += static_cast<char>(uni);
    }
    else {
        // Time to consider sf::String or some other unicode-capable string

        s.append(std::to_string(uni));
        cout << "key code :" << uni << endl;
    }

   
}
int main()
{
    Text t;
    string s = "";
    //Main Loop:
 
    while (window.isOpen()) {

        sf::Event Event;
       
        //Event Loop:

        while (window.pollEvent(Event)) {
            int uni = Event.text.unicode;
            switch (Event.type) {

            case sf::Event::Closed:
                window.close();
                break;

            case Event::Resized:
                cout << "New window: " << Event.size.width << " x " << Event.size.height << endl;

            case sf::Event::TextEntered:
              
                cout << "Event unicode " << Event.text.unicode << "  ";
                cout << "unIcode had: " << uni << endl;
              
                inputtext(uni, t, s);
                break;

            case Event::MouseMoved:
                cout << "Mouse moved" << endl;
                cout << "X: " << Event.mouseMove.x << ", Y: " << Event.mouseMove.y << endl;


            case sf::Event::MouseButtonPressed:
                sf::Vector2i Pst = sf::Mouse::getPosition(window);
                std::cout << "Mouse button has been pressed" << std::endl;
                cout << "Mouse X " << Pst.x << " : Y " << Pst.y << endl;
                cout << "Key.code:  " << Event.key.code << endl;//left =0, right=1

                switch (Event.key.code)
                {

                case sf::Mouse::Left:

                    if (Pst.x >= 100.f && Pst.x <= 500.f && Pst.y >= 300.f && Pst.y <= 600.f) { //test
                        std::cout << "LEFT KEY HAS BEEN PRESSED" << std::endl;
                        k = 1;
                    }
                    else if (Pst.x >= 900.f && Pst.x <= 1170.f && Pst.y >= 20.f && Pst.y <= 40.f) {//search
                        k = 2;
                    }
                    /*tol
                    * 1 import
                    * 2 add
                    * 3 delete
                    * 4 see top
                    * 5 statistical
                    * 6 sort
                    *
                    *
                    */
                    else if (Pst.x >= 800.f && Pst.x <= 845.f && Pst.y >= 20.f && Pst.y <= 40.f) {//sort
                        tol = 6;
                    }
                    else if (Pst.x >= 650.f && Pst.x <= 760.f && Pst.y >= 20.f && Pst.y <= 40.f) {//statistical
                        tol = 5;
                    }
                    else if (Pst.x >= 550.f && Pst.x <= 615.f && Pst.y >= 20.f && Pst.y <= 40.f) {//see top
                        tol = 4;
                    }
                    else if (Pst.x >= 450.f && Pst.x <= 510.f && Pst.y >= 20.f && Pst.y <= 40.f) {//delete
                        tol = 3;
                    }
                    else if (Pst.x >= 350.f && Pst.x <= 380.f && Pst.y >= 20.f && Pst.y <= 40.f) {//add
                        tol = 2;
                        cout << "ad" << endl;
                    }
                    else if (Pst.x >= 250.f && Pst.x <= 310.f && Pst.y >= 20.f && Pst.y <= 40.f) {//import
                        tol = 1;
                    }
                    else {
                        k = 0;
                        se = 0;
                        tol = 0;
                    }
                    break;

              
                }
              
            }


            //  window.clear(sf::Color::White);
            backgr();
            if (k == 1)
            {
                ap();
                cout << "k: " << k << endl;
            }
            else if ((k == 2)) {
                search1();
            }
            else if (tol != 0) {

                tool(tol);
            }
            else if (k == 0 || se == 0 || tol == 0) {
                backgr();
            }
    
        //    inputText(300, 500);
            t.setString(s);

            window.draw(t);
            window.display();
        }
    }


}