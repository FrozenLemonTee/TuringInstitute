//
// Created by Lenovo on 25-3-3.
//
#include <algorithm>
#include "iostream"
#include <cstdlib>
#include "gobang.h"

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

int main()
{
    menuView();
    return 0;
}

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
    // todo
}

void gameView_ShowMap(){
    std::string elements[] = {"▪", "●", "○"};
    for (auto& line : map) {
        for (int i = 0; i < 19; ++i) {
            if (i != 0)
                std::cout << " ";
            std::cout << elements[line[i]];
        }
        std::cout << std::endl;
    }
}

void winView(){
    std::cout << (isWin(cur_cords[0], cur_cords[1]) == 1 ? "黑" : "白") << "方胜利！按任意键返回主菜单......";
}

void gameView(){
    init();
    while (true){
        system(CLEAR_COMMAND);
        gameView_ShowMap();
        std::cout << (isWin(cur_cords[0], cur_cords[1]) == 1 ? "黑" : "白") << "方回合！" << std::endl;
        std::cout << "请输入落子坐标（用空格分割两个坐标分量）：" ;
        getCords();
        while (!validCord(cur_cords[0]) ||
               !validCord(cur_cords[1]) ||
               playerMove(cur_cords[0], cur_cords[1])){
            std::cout << "落子无效！请输入落子坐标（用空格分割两个坐标分量）：" ;
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