
#include<string>
#include<math.h>
#include<sstream>
#include"Button.h"
#include"Text.h"

//#include"Header.h"

using namespace std;

sf::RenderWindow window(sf::VideoMode(1000, 900), "Librarian", sf::Style::Titlebar | sf::Style::Close);

struct data_sach {
    string tensach;
    string theloai;

};

struct data_ {
    string name;
    string mssv;
    int soluong;
    data_sach* datasach;

};


int main()
{
    data_ NgMuon[20];

    int soluong_ngMuon = 0;

    bool kt_Nhap_tool = false;
    bool kt_Xuat_tool = false;
    bool kt_Xoa_tool = false;
    bool kt_TimKiem_tool = false;
    bool kt_Them_tool = false;

    //Xuat //////???

    // kiem tra phan nhapf 

    bool kt_ten = false;
    bool kt_ms = false;
    bool kt_solg = false;

    bool kt_table[8];

    for (int i = 0; i < 8; i++) {
        kt_table[i] = false;

    }

    bool kt_table_theloai[8];

    for (int i = 0; i < 8; i++) {
        kt_table_theloai[i] = false;
    }

    //Dinh nghia phong chu

    sf::Font font;
    if (!font.loadFromFile("ShortStack-Regular.otf"))
        std::cout << "Font not found!\n";

    // Thanh menu 

    Button Nhap("Nhap", { 120,100 }, 30, sf::Color::Green, sf::Color::Black);
    Nhap.setFont(font);
    Nhap.setPosition({ 50, 10 });

    Button Xuat("Xuat", { 120,100 }, 30, sf::Color::Green, sf::Color::Black);
    Xuat.setFont(font);
    Xuat.setPosition({ 200, 10 });

    Button Them("Them", { 120,100 }, 30, sf::Color::Green, sf::Color::Black);
    Them.setFont(font);
    Them.setPosition({ 350, 10 });

    Button Xoa("Xoa", { 120,100 }, 30, sf::Color::Green, sf::Color::Black);
    Xoa.setFont(font);
    Xoa.setPosition({ 500, 10 });

    Button Tim("Tim Kiem", { 200 , 50 }, 30, sf::Color::Green, sf::Color::Black);
    Tim.setFont(font);
    Tim.setPosition({ 650, 60 });

    //tim kiem
    Textbox tim_text(20, sf::Color::Red, true);
    tim_text.setPosition({ 650, 20 });
    tim_text.setLimit(true, 15);
    tim_text.setFont(font);

    Button searchbox("", { 200, 25 }, 30, sf::Color::Green, sf::Color::Black);
    searchbox.setFont(font);
    searchbox.setPosition({ 650, 20 });

    sf::Vector2f btn1_ps(200, 100);
    Button btn1("Enter", { btn1_ps }, 30, sf::Color::Green, sf::Color::Black);
    btn1.setFont(font);
    btn1.setPosition({ 100, 300 });



    ////////////////////////////////////
    //////////////////
    /////////


  /*
  **********  Thong tin ca nhan *****
    *


    */

    //vung nhap du lieu
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setSize(sf::Vector2f(880, 650));
    rectangle.setFillColor(sf::Color(200, 200, 200, 100));
    rectangle.setPosition(60, 200);
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color(100, 100, 100, 100));

    // vung  nhap thong tin sach

     //bang nhap thong tin sach
    sf::RectangleShape input_bg;
    input_bg.setSize(sf::Vector2f(840, 460));
    input_bg.setFillColor(sf::Color::White);
    input_bg.setPosition(80, 370);

    //truc giua

    sf::RectangleShape coltbl_sach(sf::Vector2f(440, 1));
    coltbl_sach.setPosition(500, 380);
    coltbl_sach.setFillColor(sf::Color::Black);
    coltbl_sach.rotate(90);

    //truc ngang, dong ke

    float tbl_x = 100;
    float tbl_y = 420;

    int sach_size = 7;

    sf::RectangleShape row_sach[8];
    for (int i = 0; i < sach_size; i++) {
        row_sach[i].setSize(sf::Vector2f(800, 1));
        row_sach[i].setFillColor(sf::Color::Black);
        row_sach[i].setPosition(tbl_x, tbl_y);
        tbl_y += 50;
    }

    //---- Ten cot ---

     //tieu de
    sf::Text imp;
    imp.setFont(font);
    imp.setString("Nhap Thong Tin");
    imp.setFillColor(sf::Color::Black);
    imp.setPosition(250.f, 200.f);
    imp.setCharacterSize(20);

    // sach
    sf::Text name_bk;
    name_bk.setFont(font);
    name_bk.setString("Ten Sach");
    name_bk.setFillColor(sf::Color::Black);
    name_bk.setPosition(180, 390);
    name_bk.setCharacterSize(20);

    //the loai
    sf::Text kind_bk;
    kind_bk.setFont(font);
    kind_bk.setString("The Loai");
    kind_bk.setFillColor(sf::Color::Black);
    kind_bk.setPosition(580, 390);
    kind_bk.setCharacterSize(20);

    //Dong 1
    //Ten sach

    sf::Vector2f pos_sach;
    pos_sach.x = 100;
    pos_sach.y = 430;


    Textbox sach_text[8];

    for (int i = 0; i < sach_size; i++) {
        //  sach_text[i].setColor(sf::Color::Black);
        sach_text[i].setTextbox(20, sf::Color::Black, true);
        sach_text[i].setFont(font);
        sach_text[i].setPosition(pos_sach);

        pos_sach.y += 50;

    }

    pos_sach.x = 100;
    pos_sach.y = 430;

    Button sach_btn1;

    sach_btn1.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    sach_btn1.setFont(font);
    sach_btn1.setPosition(pos_sach);

    pos_sach.y += 50;

    Button sach_btn2;

    sach_btn2.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    sach_btn2.setFont(font);
    sach_btn2.setPosition(pos_sach);

    pos_sach.y += 50;

    Button sach_btn3;

    sach_btn3.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    sach_btn3.setFont(font);
    sach_btn3.setPosition(pos_sach);

    pos_sach.y += 50;

    Button sach_btn4;

    sach_btn4.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    sach_btn4.setFont(font);
    sach_btn4.setPosition(pos_sach);

    pos_sach.y += 50;

    Button sach_btn5;

    sach_btn5.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    sach_btn5.setFont(font);
    sach_btn5.setPosition(pos_sach);

    pos_sach.y += 50;

    Button sach_btn6;

    sach_btn6.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    sach_btn6.setFont(font);
    sach_btn6.setPosition(pos_sach);

    pos_sach.y += 50;

    Button sach_btn7;

    sach_btn7.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    sach_btn7.setFont(font);
    sach_btn7.setPosition(pos_sach);

    pos_sach.y += 50;



    ////the loai

    sf::Vector2f pos_theloai;
    pos_theloai.x = 505;
    pos_theloai.y = 430;

    int theloai_size = 7;

    Textbox theloai_text[8];

    for (int i = 0; i < theloai_size; i++) {
        theloai_text[i].setColor(sf::Color::Black);
        theloai_text[i].setTextbox(20, sf::Color::Magenta, true);
        theloai_text[i].setFont(font);
        theloai_text[i].setPosition(pos_theloai);

        pos_theloai.y += 50;

    }

    pos_theloai.x = 505;
    pos_theloai.y = 430;

    Button theloai_btn1;

    theloai_btn1.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    theloai_btn1.setFont(font);
    theloai_btn1.setPosition(pos_theloai);
    pos_theloai.y += 50;

    //2
    Button theloai_btn2;

    theloai_btn2.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    theloai_btn2.setFont(font);
    theloai_btn2.setPosition(pos_theloai);
    pos_theloai.y += 50;

    //3
    Button theloai_btn3;

    theloai_btn3.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    theloai_btn3.setFont(font);
    theloai_btn3.setPosition(pos_theloai);
    pos_theloai.y += 50;

    //4
    Button theloai_btn4;

    theloai_btn4.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    theloai_btn4.setFont(font);
    theloai_btn4.setPosition(pos_theloai);
    pos_theloai.y += 50;

    //5
    Button theloai_btn5;

    theloai_btn5.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    theloai_btn5.setFont(font);
    theloai_btn5.setPosition(pos_theloai);
    pos_theloai.y += 50;

    //6
    Button theloai_btn6;

    theloai_btn6.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    theloai_btn6.setFont(font);
    theloai_btn6.setPosition(pos_theloai);
    pos_theloai.y += 50;

    //7
    Button theloai_btn7;

    theloai_btn7.setButton("", { 395, 30 }, 30, sf::Color::White, sf::Color::Red);
    theloai_btn7.setFont(font);
    theloai_btn7.setPosition(pos_theloai);
    pos_theloai.y += 50;


    //ho ten
    sf::Text hoten;
    hoten.setPosition(80, 220);
    hoten.setFont(font);
    hoten.setFillColor(sf::Color::Black);
    hoten.setString("Ho & Ten: ");
    hoten.setCharacterSize(20);

    Textbox ten_textbox(20, sf::Color::Red, true);
    ten_textbox.setPosition({ 80, 250 });
    ten_textbox.setLimit(true, 25);
    ten_textbox.setFont(font);

    Button namebox("", { 350, 30 }, 30, sf::Color::White, sf::Color::Black);
    namebox.setFont(font);
    namebox.setPosition({ 80, 250 });

    //mssv
    sf::Text msv;
    msv.setFont(font);
    msv.setString("MSSV: ");
    msv.setFillColor(sf::Color::Black);
    msv.setPosition(80.f, 280.f);
    msv.setCharacterSize(20);

    Textbox mssv(20, sf::Color::Red, true);
    mssv.setPosition({ 80, 310 });
    mssv.setLimit(true, 15);
    mssv.setFont(font);

    Button msvbox("", { 200, 25 }, 30, sf::Color::White, sf::Color::Black);
    msvbox.setFont(font);
    msvbox.setPosition({ 80, 310 });

    //So luong
    sf::Text slg;
    slg.setFont(font);
    slg.setString("So luong: ");
    slg.setFillColor(sf::Color::Black);
    slg.setPosition(500.f, 280.f);
    slg.setCharacterSize(20);

    Textbox sl(20, sf::Color::Red, true);
    sl.setPosition({ 500, 310 });
    sl.setLimit(true, 10);
    sl.setFont(font);

    Button slbox("", { 200, 25 }, 30, sf::Color::White, sf::Color::Black);
    slbox.setFont(font);
    slbox.setPosition({ 500, 310 });

    sf::Vector2f sub_ps(300, 740);
    Button sub_btn("Next", { 100,80 }, 30, sf::Color::Green, sf::Color::Black);
    sub_btn.setFont(font);
    sub_btn.setPosition({ 740 , 250 });

    bool kt_sub_btn = false;

    //////              //////      ////        /////
    /////  Xem thong tin////
    /////               ////

    // bang xem thong tin

    sf::RectangleShape Xuat_bgr(sf::Vector2f(120, 50));
    Xuat_bgr.setSize(sf::Vector2f(950, 700));
    Xuat_bgr.setFillColor(sf::Color::White);
    Xuat_bgr.setPosition(30, 180);
    Xuat_bgr.setOutlineThickness(2);
    Xuat_bgr.setOutlineColor(sf::Color(100, 100, 100, 100));

    //truc ngang, dong ke

    float view_row_x = 40;
    float view_row_y = 250;

    int row_view = 12;

    sf::RectangleShape row_table_view[12];
    for (int i = 0; i < row_view; i++) {
        row_table_view[i].setSize(sf::Vector2f(930, 1));
        row_table_view[i].setFillColor(sf::Color::Black);
        row_table_view[i].setPosition(view_row_x, view_row_y);
        view_row_y += 50;
    }

    //cot phan cach

    //sTT

    sf::RectangleShape col_view_stt(sf::Vector2f(650, 1));
    col_view_stt.setPosition(100, 200);
    col_view_stt.setFillColor(sf::Color::Black);
    col_view_stt.rotate(90);

    sf::RectangleShape col_view_mssv(sf::Vector2f(650, 1));
    col_view_mssv.setPosition(500, 200);
    col_view_mssv.setFillColor(sf::Color::Black);
    col_view_mssv.rotate(90);

    sf::RectangleShape col_view_solg(sf::Vector2f(650, 1));
    col_view_solg.setPosition(800, 200);
    col_view_solg.setFillColor(sf::Color::Black);
    col_view_solg.rotate(90);

    sf::Text stt_text_xuat;
    stt_text_xuat.setFont(font);
    stt_text_xuat.setFillColor(sf::Color::Black);
    stt_text_xuat.setString("STT");
    stt_text_xuat.setCharacterSize(20);
    stt_text_xuat.setPosition(50, 220);


    sf::Text stt_size[11];
    float stt_pos_x = 70;
    float stt_pos_y = 270;
    int size_STT = 11;

    int num_stt = 1;
    for (int i = 0; i < 11; i++) {
        stt_size[i].setFont(font);
        stt_size[i].setFillColor(sf::Color::Black);
        stt_size[i].setCharacterSize(20);
        stt_size[i].setPosition(stt_pos_x, stt_pos_y);
        stt_pos_y += 50;


        string result;
        ostringstream convert;
        convert << num_stt;
        result = convert.str();
        stt_size[i].setString(result);
        num_stt++;

    }

    sf::Text ten_text_xuat;
    ten_text_xuat.setFont(font);
    ten_text_xuat.setFillColor(sf::Color::Black);
    ten_text_xuat.setString("Ho va ten");
    ten_text_xuat.setCharacterSize(20);
    ten_text_xuat.setPosition(250, 220);

    sf::Text mssv_text_xuat;
    mssv_text_xuat.setFont(font);
    mssv_text_xuat.setFillColor(sf::Color::Black);
    mssv_text_xuat.setString("MSSV");
    mssv_text_xuat.setCharacterSize(20);
    mssv_text_xuat.setPosition(550, 220);

    sf::Text solg_text_xuat;
    solg_text_xuat.setFont(font);
    solg_text_xuat.setFillColor(sf::Color::Black);
    solg_text_xuat.setString("So luong");
    solg_text_xuat.setCharacterSize(20);
    solg_text_xuat.setPosition(850, 220);

  


    while (window.isOpen()) {

        sf::Event Event;

        //Event Loop:

        while (window.pollEvent(Event)) {

            switch (Event.type) {

            case sf::Event::Closed:
                window.close();
                break;
                //Kiem tra phan tu nao se duoc xac dinh de  nhap 
            case sf::Event::TextEntered:

                if (kt_TimKiem_tool) {
                    tim_text.typedOn(Event);
                }
                if (kt_ten) {
                    ten_textbox.typedOn(Event);
                }
                if (kt_ms) {
                    mssv.typedOn(Event);
                }
                if (kt_solg) {
                    sl.typedOn(Event);
                }

                //// Xac dinh o can nhap :: ten sach

                if (kt_table[0]) {
                    sach_text[0].typedOn(Event);

                }
                if (kt_table[1]) {
                    sach_text[1].typedOn(Event);

                }
                if (kt_table[2]) {
                    sach_text[2].typedOn(Event);

                }
                if (kt_table[3]) {
                    sach_text[3].typedOn(Event);

                }
                if (kt_table[4]) {
                    sach_text[4].typedOn(Event);

                }
                if (kt_table[5]) {
                    sach_text[5].typedOn(Event);

                }
                if (kt_table[6]) {
                    sach_text[6].typedOn(Event);

                }
                if (kt_table[7]) {
                    sach_text[7].typedOn(Event);

                }


                //      

                //// Xac dinh o can nhap :: the loai

                if (kt_table_theloai[0]) {
                    theloai_text[0].typedOn(Event);
                }

                if (kt_table_theloai[1]) {
                    theloai_text[1].typedOn(Event);
                }
                if (kt_table_theloai[2]) {
                    theloai_text[2].typedOn(Event);
                }
                if (kt_table_theloai[3]) {
                    theloai_text[3].typedOn(Event);
                }
                if (kt_table_theloai[4]) {
                    theloai_text[4].typedOn(Event);
                }
                if (kt_table_theloai[5]) {
                    theloai_text[5].typedOn(Event);
                }
                if (kt_table_theloai[6]) {
                    theloai_text[6].typedOn(Event);
                }
                if (kt_table_theloai[7]) {
                    theloai_text[7].typedOn(Event);
                }


                break;

                // Kiem tra vi tri cua chuot -> thay doi mau sac o chon 
            case sf::Event::MouseMoved:

                  // cout << "Mouse moved" << endl;
                //   cout << "X: " << Event.mouseMove.x << ", Y: " << Event.mouseMove.y << endl;
                   

                if (btn1.isMouseOver(window)) {
                    btn1.setBackColor(sf::Color::Magenta);
                }
                else {
                    btn1.setBackColor(sf::Color::Green);
                }

                if (Them.isMouseOver(window)) {
                    Them.setBackColor(sf::Color::Magenta);
                }
                else {
                    Them.setBackColor(sf::Color::Green);
                }

                if (Xoa.isMouseOver(window)) {
                    Xoa.setBackColor(sf::Color::Magenta);
                }
                else {
                    Xoa.setBackColor(sf::Color::Green);
                }

                if (Nhap.isMouseOver(window)) {
                    Nhap.setBackColor(sf::Color::Magenta);
                }
                else {
                    Nhap.setBackColor(sf::Color::Green);
                }

                if (Xuat.isMouseOver(window)) {
                    Xuat.setBackColor(sf::Color::Magenta);
                }
                else {
                    Xuat.setBackColor(sf::Color::Green);
                }

                if (Tim.isMouseOver(window)) {
                    Tim.setBackColor(sf::Color::Magenta);
                }
                else {
                    Tim.setBackColor(sf::Color::Green);
                }
                if (sub_btn.isMouseOver(window)) {
                    sub_btn.setBackColor(sf::Color::Green);
                }
                else
                {
                    sub_btn.setBackColor(sf::Color(250, 255, 150, 255));
                }

                break;

                // kiem tra vi tri chuot da duoc nhan 
            case sf::Event::MouseButtonPressed:

                if (Nhap.isMouseOver(window)) {
                    std::cout << "Nhap\n";
                    kt_Nhap_tool = true;

                    kt_Xuat_tool = false;
                    kt_Xoa_tool = false;
                    kt_Them_tool = false;
                    kt_TimKiem_tool = false;
                }


                if (Xuat.isMouseOver(window)) {
                    cout << "Xuat\n";
                    kt_Xuat_tool = true;

                    kt_Nhap_tool = false;
                    kt_Xoa_tool = false;
                    kt_Them_tool = false;
                    kt_TimKiem_tool = false;


                }

                if (Xoa.isMouseOver(window)) {
                    cout << "Xoa\n";
                    kt_Xoa_tool = true;

                    kt_Xuat_tool = false;
                    kt_Nhap_tool = false;
                    kt_Them_tool = false;
                    kt_TimKiem_tool = false;

                }

                if (Them.isMouseOver(window)) {
                    cout << "Them \n";
                    kt_Them_tool = true;


                    kt_Xuat_tool = false;
                    kt_Nhap_tool = false;
                    kt_Xoa_tool = false;
                    kt_TimKiem_tool = false;

                }
                if (Tim.isMouseOver(window) || searchbox.isMouseOver(window)) {
                    std::cout << "Tim kiem\n";
                    kt_TimKiem_tool = true;



                }

                if (btn1.isMouseOver(window)) {
                    std::cout << "Enter\n";
                    kt_TimKiem_tool = true;



                }


                //Nhap
                if (namebox.isMouseOver(window)) {
                    kt_ten = true;
                    std::cout << "Ten\n";
                }
                else {
                    kt_ten = false;
                }
                if (msvbox.isMouseOver(window)) {
                    std::cout << "MSSV\n";
                    kt_ms = true;
                }
                else {
                    kt_ms = false;
                }
                if (slbox.isMouseOver(window)) {
                    std::cout << "So luong\n";
                    kt_solg = true;
                }
                else {
                    kt_solg = false;
                }

                if (sub_btn.isMouseOver(window)) {
                    std::cout << "Entered\n";
                    kt_sub_btn = true;
                }
                else
                {
                    kt_sub_btn = false;
                }



                //Kiem tra phan nhap ten sach da nhan hay chua?
                //1

                if (sach_btn1.isMouseOver(window)) {
                    kt_table[0] = true;

                }
                else {
                    kt_table[0] = false;
                }
                //2
                if (sach_btn2.isMouseOver(window)) {
                    kt_table[1] = true;

                }
                else {
                    kt_table[1] = false;
                }
                //3

                if (sach_btn3.isMouseOver(window)) {
                    kt_table[2] = true;

                }
                else {
                    kt_table[2] = false;
                }
                //4
                if (sach_btn4.isMouseOver(window)) {
                    kt_table[3] = true;

                }
                else {
                    kt_table[3] = false;
                }
                //5
                if (sach_btn5.isMouseOver(window)) {
                    kt_table[4] = true;

                }
                else {
                    kt_table[4] = false;
                }
                //6
                if (sach_btn6.isMouseOver(window)) {
                    kt_table[5] = true;

                }
                else {
                    kt_table[5] = false;
                }
                //7
                if (sach_btn7.isMouseOver(window)) {
                    kt_table[6] = true;

                }
                else {
                    kt_table[6] = false;
                }




                ////kiem tra the loai da duoc nhan hay k

                if (theloai_btn1.isMouseOver(window)) {
                    kt_table_theloai[0] = true;

                }
                else {
                    kt_table_theloai[0] = false;
                }
                //2
                if (theloai_btn2.isMouseOver(window)) {
                    kt_table_theloai[1] = true;

                }
                else {
                    kt_table_theloai[1] = false;
                }
                //3
                if (theloai_btn3.isMouseOver(window)) {
                    kt_table_theloai[2] = true;

                }
                else {
                    kt_table_theloai[2] = false;
                }
                //4
                if (theloai_btn4.isMouseOver(window)) {
                    kt_table_theloai[3] = true;

                }
                else {
                    kt_table_theloai[3] = false;
                }
                //5
                if (theloai_btn5.isMouseOver(window)) {
                    kt_table_theloai[4] = true;

                }
                else {
                    kt_table_theloai[4] = false;
                }
                //6
                if (theloai_btn6.isMouseOver(window)) {
                    kt_table_theloai[5] = true;

                }
                else {
                    kt_table_theloai[5] = false;
                }
                //7
                if (theloai_btn7.isMouseOver(window)) {
                    kt_table_theloai[6] = true;

                }
                else {
                    kt_table_theloai[6] = false;
                }

                break;

            }
            window.clear(sf::Color::White);


            Nhap.drawTo(window);
            Xuat.drawTo(window);
            Them.drawTo(window);
            Xoa.drawTo(window);
            Tim.drawTo(window);
            btn1.drawTo(window);
            btn1.reset();

            searchbox.drawTo(window);

            tim_text.drawTo(window);

            //////////////////////////////////////////////

            // Nhap thong tin
            if (kt_Nhap_tool) {
                // Vung nhap 
                    //ten 
                window.draw(rectangle);
                window.draw(imp);


                //ho ten
                window.draw(hoten);
                namebox.drawTo(window);
                ten_textbox.drawTo(window);

                //msv
                window.draw(msv);
                msvbox.drawTo(window);
                mssv.drawTo(window);

                // so luong
                window.draw(slg);
                slbox.drawTo(window);
                sl.drawTo(window);

                sub_btn.drawTo(window);


                // Xac nhap o nhap thong tin

                // Nhap:: code

                // Nhap thong tin sach

                // Bang nhap thong tin
                window.draw(input_bg);

                window.draw(coltbl_sach);
                for (int i = 0; i < sach_size; i++) {
                    window.draw(row_sach[i]);
                }

                //ten cot
                window.draw(kind_bk);//the loai
                window.draw(name_bk);//ten sach

               //bang nhap thong tin

                sach_btn1.drawTo(window);
                sach_btn2.drawTo(window);
                sach_btn3.drawTo(window);
                sach_btn4.drawTo(window);
                sach_btn5.drawTo(window);
                sach_btn6.drawTo(window);
                sach_btn7.drawTo(window);


                for (int i = 0; i < sach_size; i++) {

                    //ten
                    sach_text[i].drawTo(window);

                }

                // the loai
                theloai_btn1.drawTo(window);
                theloai_btn2.drawTo(window);
                theloai_btn3.drawTo(window);
                theloai_btn4.drawTo(window);
                theloai_btn5.drawTo(window);
                theloai_btn6.drawTo(window);
                theloai_btn7.drawTo(window);
                for (int i = 0; i < theloai_size; i++) {

                    theloai_text[i].drawTo(window);

                }

                // xoa phan cu -> nhap phan tiep theo

                /*
                Toi da 20 ng muon sach
                Moi ng toi da 8 quyen sach

                */

                if (kt_sub_btn) {


                    cout << "Luot : " << soluong_ngMuon << endl;


                    //ep kieu string sang int 


                    string laysoluong = sl.getText();
                    cout << "So luong (string): " << laysoluong << endl;

                    int l1 = laysoluong.length();

                    int num1 = 0;//so luong sach

                    for (int i = l1 - 1; i >= 0; --i) {
                        num1 += (int)(laysoluong[i] - '0') * pow(10, l1 - i - 1);
                    }

                    cout << "So luong (int::num1) = " << num1 << '\n';

                    if (num1 <= 0 || num1 > 8) {
                        sl.reset();
                        kt_sub_btn = false;
                        cout << "So luong khong hop le \n";
                        break;
                    }

                    NgMuon[soluong_ngMuon].datasach = new data_sach[num1];


                    for (int i = 0; i < num1; i++) {

                        NgMuon[0].datasach[i].theloai = theloai_text[i].getText();

                        cout << "The loai: " << NgMuon[soluong_ngMuon].datasach[i].theloai << endl;
                    }

                    for (int i = 0; i < num1; i++) {

                        //ten

                        NgMuon[soluong_ngMuon].datasach[i].tensach = sach_text[i].getText();

                        cout << "Ten sach: " << NgMuon[soluong_ngMuon].datasach[i].tensach << endl;
                    }
                    for (int i = 0; i < 8; i++) {
                        theloai_text[i].reset();
                        sach_text[i].reset();
                    }

                    string ten = ten_textbox.getText();
                    NgMuon[soluong_ngMuon].name = ten;

                    cout << "Ten nguoi muon : " << NgMuon[soluong_ngMuon].name << endl;

                    ten_textbox.reset();

                    string MaSV = mssv.getText();

                    NgMuon[soluong_ngMuon].mssv = MaSV;
                    cout << "Ma Sinh Vien: " << NgMuon[soluong_ngMuon].mssv << endl;



                    mssv.reset();
                    sl.reset();
                                        
                    kt_sub_btn = false;
                    soluong_ngMuon++;

                }
                ///
            }
            
            if (kt_Them_tool) {
                {
                    // Vung nhap 
                        //ten 
                    window.draw(rectangle);
                    sf::Text them_text;
                    them_text.setFont(font);
                    them_text.setString("Them Thong Tin");
                    them_text.setFillColor(sf::Color::Black);
                    them_text.setPosition(250.f, 200.f);
                    them_text.setCharacterSize(20);
                    window.draw(them_text);


                    //ho ten
                    window.draw(hoten);
                    namebox.drawTo(window);
                    ten_textbox.drawTo(window);

                    //msv
                    window.draw(msv);
                    msvbox.drawTo(window);
                    mssv.drawTo(window);

                    // so luong
                    window.draw(slg);
                    slbox.drawTo(window);
                    sl.drawTo(window);

                    sub_btn.drawTo(window);


                    // Xac nhap o nhap thong tin

                    // Nhap:: code

                    // Nhap thong tin sach

                    // Bang nhap thong tin
                    window.draw(input_bg);

                    window.draw(coltbl_sach);
                    for (int i = 0; i < sach_size; i++) {
                        window.draw(row_sach[i]);
                    }

                    //ten cot
                    window.draw(kind_bk);//the loai
                    window.draw(name_bk);//ten sach

                   //bang nhap thong tin

                    sach_btn1.drawTo(window);
                    sach_btn2.drawTo(window);
                    sach_btn3.drawTo(window);
                    sach_btn4.drawTo(window);
                    sach_btn5.drawTo(window);
                    sach_btn6.drawTo(window);
                    sach_btn7.drawTo(window);


                    for (int i = 0; i < sach_size; i++) {

                        //ten
                        sach_text[i].drawTo(window);

                    }

                    // the loai
                    theloai_btn1.drawTo(window);
                    theloai_btn2.drawTo(window);
                    theloai_btn3.drawTo(window);
                    theloai_btn4.drawTo(window);
                    theloai_btn5.drawTo(window);
                    theloai_btn6.drawTo(window);
                    theloai_btn7.drawTo(window);
                    for (int i = 0; i < theloai_size; i++) {

                        theloai_text[i].drawTo(window);

                    }

                    // xoa phan cu -> nhap phan tiep theo

                    /*
                    Toi da 100 ng muon sach
                    Moi ng toi da 8 quyen sach

                    */

                    if (kt_sub_btn) {


                        cout << "Luot : " << soluong_ngMuon << endl;


                        //ep kieu string sang int 


                        string laysoluong = sl.getText();
                        cout << "So luong (string): " << laysoluong << endl;

                        int l1 = laysoluong.length();

                        int num1 = 0;//so luong sach

                        for (int i = l1 - 1; i >= 0; --i) {
                            num1 += (int)(laysoluong[i] - '0') * pow(10, l1 - i - 1);
                        }
                        cout << "So luong (int::num1) = " << num1 << '\n';

                        if (num1 <= 0 || num1 > 8) {
                            sl.reset();
                            kt_sub_btn = false;
                            cout << "So luong khong hop le \n";
                            break;
                        }

                        NgMuon[soluong_ngMuon].datasach = new data_sach[num1];


                        for (int i = 0; i < num1; i++) {

                            NgMuon[0].datasach[i].theloai = theloai_text[i].getText();

                            cout << "The loai: " << NgMuon[soluong_ngMuon].datasach[i].theloai << endl;
                        }

                        for (int i = 0; i < num1; i++) {

                            //ten

                            NgMuon[soluong_ngMuon].datasach[i].tensach = sach_text[i].getText();

                            cout << "Ten sach: " << NgMuon[soluong_ngMuon].datasach[i].tensach << endl;
                        }

                        for (int i = 0; i < 8; i++) {
                            theloai_text[i].reset();
                            sach_text[i].reset();
                        }
                        string ten = ten_textbox.getText();
                        NgMuon[soluong_ngMuon].name = ten;

                        cout << "Ten nguoi muon : " << NgMuon[soluong_ngMuon].name << endl;

                        ten_textbox.reset();

                        string MaSV = mssv.getText();

                        NgMuon[soluong_ngMuon].mssv = MaSV;
                        cout << "Ma Sinh Vien: " << NgMuon[soluong_ngMuon].mssv << endl;

                        mssv.reset();
                        sl.reset();

                        kt_sub_btn = false;
                        soluong_ngMuon++;

                    }
                    
                }
            }

            if (kt_Xuat_tool) {

                /*
                lay gia tri gan vao sf::Text -> draw;
                cap phat bo nho cho text

                */

                window.draw(Xuat_bgr);
                // Bang xem thong tin

                window.draw(col_view_stt);
                window.draw(stt_text_xuat);
                window.draw(ten_text_xuat);
                window.draw(mssv_text_xuat);
                window.draw(solg_text_xuat);

                window.draw(col_view_mssv);
                window.draw(col_view_solg);

                for (int i = 0; i < row_view; i++) {
                    window.draw(row_table_view[i]);
                }
                for (int i = 0; i < 11; i++) {
                    window.draw(stt_size[i]);
                }

                // Xuat 

                float ten_xuat_pos_x = 110;
                float ten_xuat_pos_y = 270;

                sf::Text Ten_xuat[11];
                for (int i = 0; i < soluong_ngMuon; i++) {
                    Ten_xuat[i].setFont(font);
                    Ten_xuat[i].setCharacterSize(20);
                    Ten_xuat[i].setFillColor(sf::Color::Black);
                    Ten_xuat[i].setPosition(ten_xuat_pos_x, ten_xuat_pos_y);
                   // Ten_xuat[i].setString("Ten");
                    Ten_xuat[i].setString(NgMuon[i].name);
                    ten_xuat_pos_y += 50;
                    window.draw(Ten_xuat[i]);
                }

                float msv_xuat_pos_x = 510;
                float msv_xuat_pos_y = 270;

                sf::Text msv_xuat[11];
                for (int i = 0; i < soluong_ngMuon; i++) {
                    msv_xuat[i].setFont(font);
                    msv_xuat[i].setCharacterSize(20);
                    msv_xuat[i].setFillColor(sf::Color::Black);
                    msv_xuat[i].setPosition(msv_xuat_pos_x, msv_xuat_pos_y);
                    msv_xuat[i].setString(NgMuon[i].mssv);
                    msv_xuat_pos_y += 50;
                    window.draw(msv_xuat[i]);

                }

                float solg_xuat_pos_x = 810;
                float solg_xuat_pos_y = 270;

                sf::Text solg_xuat[11];
                for (int i = 0; i < soluong_ngMuon; i++) {
                    solg_xuat[i].setFont(font);
                    solg_xuat[i].setCharacterSize(20);
                    solg_xuat[i].setFillColor(sf::Color::Black);
                    solg_xuat[i].setPosition(solg_xuat_pos_x, solg_xuat_pos_y);

                    cout <<"So luong sach" <<NgMuon[i].soluong<<endl;
                    string result;
                    ostringstream convert;
                    convert << NgMuon[i].soluong;
                    result = convert.str();
                    solg_xuat[i].setString(result);

                    solg_xuat_pos_y += 50;

                    window.draw(solg_xuat[i]);
                }

                
            }

            if (kt_Xoa_tool) {

                sf::RectangleShape input_bg;
                input_bg.setSize(sf::Vector2f(500, 60));
                input_bg.setFillColor(sf::Color(255, 128, 128, 120));
                input_bg.setPosition(250, 115);

                window.draw(input_bg);
                sf::Text xoa_title;

                xoa_title.setFont(font);
                xoa_title.setString("XOA");
                xoa_title.setFillColor(sf::Color::Black);
                xoa_title.setPosition(450, 110);
                xoa_title.setCharacterSize(50);



                window.draw(Xuat_bgr);
                // Bang xem thong tin

                window.draw(col_view_stt);
                window.draw(stt_text_xuat);
                window.draw(ten_text_xuat);
                window.draw(mssv_text_xuat);
                window.draw(solg_text_xuat);

                window.draw(col_view_mssv);
                window.draw(col_view_solg);

                for (int i = 0; i < row_view; i++) {
                    window.draw(row_table_view[i]);
                }
                for (int i = 0; i < 11; i++) {
                    window.draw(stt_size[i]);
                }
                window.draw(xoa_title);

                // Xuat 

                float ten_xuat_pos_x = 100;
                float ten_xuat_pos_y = 270;

                sf::Text Ten_xuat[11];
                for (int i = 0; i < soluong_ngMuon; i++) {
                    Ten_xuat[i].setFont(font);
                    Ten_xuat[i].setCharacterSize(20);
                    Ten_xuat[i].setFillColor(sf::Color::Black);
                    Ten_xuat[i].setPosition(ten_xuat_pos_x, ten_xuat_pos_y);
                    Ten_xuat[i].setString(NgMuon[i].name);
                    ten_xuat_pos_y += 50;
                }

                float msv_xuat_pos_x = 510;
                float msv_xuat_pos_y = 270;

                sf::Text msv_xuat[11];
                for (int i = 0; i < soluong_ngMuon; i++) {
                    msv_xuat[i].setFont(font);
                    msv_xuat[i].setCharacterSize(20);
                    msv_xuat[i].setFillColor(sf::Color::Black);
                    msv_xuat[i].setPosition(msv_xuat_pos_x, msv_xuat_pos_y);
                    msv_xuat[i].setString(NgMuon[i].mssv);
                    msv_xuat_pos_y += 50;
                }

                float solg_xuat_pos_x = 810;
                float solg_xuat_pos_y = 270;

                sf::Text solg_xuat[11];
                for (int i = 0; i < soluong_ngMuon; i++) {
                    solg_xuat[i].setFont(font);
                    solg_xuat[i].setCharacterSize(20);
                    solg_xuat[i].setFillColor(sf::Color::Black);
                    solg_xuat[i].setPosition(solg_xuat_pos_x, solg_xuat_pos_y);

                    string result;
                    ostringstream convert;
                    convert << NgMuon[i].soluong;
                    result = convert.str();
                    solg_xuat[i].setString(result);

                    solg_xuat_pos_y += 50;
                }
                kt_Xoa_tool = false;

            }

            if (kt_TimKiem_tool) {
                
            }
            window.display();
        }
    }
    
/*
    for (int i = 0; i < 20; i++) {
        delete NgMuon->datasach;
    }
    */
    return 0;

}


