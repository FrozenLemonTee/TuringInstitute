//
// Created by Lenovo on 25-3-3.
//
#include <algorithm>
#include "iostream"
#include <cstdlib>
#include "../include/gobang.h"

// 定义平台相关信息
#ifdef _WIN32
#include <conio.h>
#define CLEAR_COMMAND "cls"
#else
#include <termios.h>
#include <unistd.h>
#define CLEAR_COMMAND "clear"

    void disableEcho() {
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    }

    void enableEcho() {
        struct termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        oldt.c_lflag |= (ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
#endif

#define UP_KEY 72   // 上箭头
#define DOWN_KEY 80 // 下箭头

int map[19][19];

int flag;

int cur_cords[2];

void init(){
    for (auto& i : map){
        for (auto& j : i) {
            j = 0;
        }
    }
    flag = 0;
}

bool validCord(int cord){
    return cord >= 0 && cord <= 18;
}

bool getSide() {
    return flag % 2 == 1;
}

void getCords() {
    std::string s;
    for (auto& cur_cord : cur_cords) {
        std::cin >> s;
        cur_cord = std::stoi(s);
    }
}

int isWin(int x, int y){
    int side = getSide() + 1; // 黑方回合时，getSide()为0，map[x][y] = 1为黑方的子；白方回合时，getSide()为1，map[x][y] = 2为白方的子
    return std::max({isWinImpl(x, y, 1, 0, side), isWinImpl(x, y, 0, 1, side),
                     isWinImpl(x, y, 1, -1, side), isWinImpl(x, y, 1, 1, side)});
}

int isWinImpl(int x, int y, int dx, int dy, int side) {
    int count = 1; // 统计当前连珠的数量
    for (int direction = -1; direction <= 1; direction += 2){
        for (int delta = 1; validCord(x + delta * direction * dx) && validCord(y + delta * direction * dy); ++delta){
            if (map[x + delta * direction * dx][y + delta * direction * dy] == side){
                count += 1;
            } else{
                break;
            }
            if (count == 5)
                return side;
        }
    }
    return 0;
}

int playerMove(int x, int y){
    if (map[x][y] == 0){
        map[x][y] = getSide() + 1;
        return true;
    }
    return false;
}

void menuView(){
    std::string choices[] = {"Game Start", "Settings", "Exit"};
    int choice_count = sizeof(choices) / sizeof(choices[0]);
    int highlight = 0;
    char ch;
    while (true){
        system(CLEAR_COMMAND);
        std::cout << "\n==== Gobang 1.0 by FrozenLemonTee ====\n";
        for (int i = 0; i < choice_count; ++i) {
            if (i == highlight)
                std::cout << "> " << choices[i] << " <\n";
            else
                std::cout << "  " << choices[i] << "\n";
        }
        std::cout << "\n======================================\n";

        ch = getChar();
        if (ch == 'w' || ch == UP_KEY) {
            highlight = (highlight - 1 + choice_count) % choice_count;
        } else if (ch == 's' || ch == DOWN_KEY) {
            highlight = (highlight + 1) % choice_count;
        } else if (ch == '\n' || ch == '\r') { // 处理 Enter 键
            if (highlight == 0) {
                gameView();
            } else if (highlight == 1) {
                system(CLEAR_COMMAND);
                std::cout << "\nComing soon! Press any key to return...\n";
                getChar();
            } else if (highlight == 2) {
                exit(0);
            }
        }
    }
}

void gameView_ShowMap(){
    std::string elements[] = {".", "X", "O"};
    std::cout << "   ";
    for (int i = 0; i < 19; ++i) {
        std::cout << (i < 10 ? " " : "") << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 19; ++i) {
        std::cout << (i < 10 ? " " : "") << i << " ";
        for (int j = 0; j < 19; ++j) {
            std::cout << " " << elements[map[i][j]] << " ";
        }
        std::cout << std::endl;
    }
}

void winView(){
    system(CLEAR_COMMAND);
    gameView_ShowMap();
    std::cout << (isWin(cur_cords[0], cur_cords[1]) == 1 ? "Black" : "White") << " wins! Press any key to return to the main menu......";
}

void gameView(){
    init();
    while (true){
        system(CLEAR_COMMAND);
        gameView_ShowMap();
        std::cout << (getSide() == 0 ? "Black" : "White") << "\'s turn! " << std::endl;
        std::cout << "Please enter the coordinates of the drop (split the two coordinate components with a space):" ;
        getCords();
        while (!validCord(cur_cords[0]) ||
               !validCord(cur_cords[1]) ||
               !playerMove(cur_cords[0], cur_cords[1])){
            system(CLEAR_COMMAND);
            gameView_ShowMap();
            std::cout << (getSide() == 0 ? "Black" : "White") << "\'s turn! " << std::endl;
            std::cout << "The drop is invalid! Please enter the coordinates of the drop (split the two coordinate components with a space):" ;
            getCords();
        }
        if (isWin(cur_cords[0], cur_cords[1])){
            system(CLEAR_COMMAND);
            winView();
            if (getChar())
                break;
        }
        flag += 1;
    }
}

char getChar() {
#ifdef _WIN32
    return static_cast<char>(_getch());
#else
    disableEcho();
    char ch;
    std::cin >> std::noskipws >> ch;
    enableEcho();
    return ch;
#endif
}