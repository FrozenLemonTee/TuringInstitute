//
// Created by Lenovo on 25-3-3.
//

#ifndef TURINGINSTITUTE_GOBANG_H
#define TURINGINSTITUTE_GOBANG_H

//C/C++:
// -------------------- 数据设计 --------------------
/*
    棋盘:
        map[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: map[3][6] = 1  表示(3,6)的位置是黑子
*/
extern int map[19][19];

// 表示当前回合数  偶数表示黑棋落子  奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子  由黑方落子
extern int flag;

/*
 * 新增变量，用于接受用户落子坐标的缓冲区
 * */
extern int cur_cords[2];

// -------------------- 数据设计 --------------------


// -------------------- service --------------------
/*
    负责人: 张三
    功能: init: 初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
*/
void init();

/* 新增辅助函数
 * 功能：判断给定的落子坐标分量是否有效
 * 参数：
 *      cord: 当前落子的坐标分量
 *  返回值:
 *      false表示坐标分量无效
 *      true表示坐标分量有效
 * */
bool validCord(int cord);

/* 新增辅助函数
 * 功能：判断当前回合轮到哪方落子
 *  返回值:
 *      false表示轮到黑方落子
 *      true表示轮到白方落子
 * */
bool getSide();

/* 新增辅助函数
 * 功能：接收用户的落子处坐标输入
 *  返回值:
        void
 * */
void getCords();

/*
    *难点1
    负责人: 张三
    功能: isWin: 根据传入的坐标(map对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y);

/* 新增辅助函数
 * 功能：isWin的具体判断逻辑，判断水平、竖直、主对角线、副对角线中的某个方向（正反都要）上是否有五颗连珠
 * 参数：
 *      x: 当前回合落子的x坐标
 *      y: 当前回合落子的y坐标
 *      dx：这个方向上x的更新情况，0表示x不更新，1表示x递增，-1表示x递减
 *      dy：这个方向上y的更新情况，0表示y不更新，1表示y递增，-1表示y递减
 *      side: 当前下子方，1表示黑方，2表示白方
 *  返回值:
 *      0表示没有获胜
 *      1表示黑子胜利
 *      2表示白子胜利
 * */
int isWinImpl(int x, int y, int dx, int dy, int side);

/*
    负责人: 张三
    功能: playerMove: 在指定位置落子
        如果map[x][y]是空地 则修改map[x][y]的值:改为相应颜色(flag对应颜色)        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    负责人: 张三
    功能: menuView: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        进入游戏: 调用游戏界面函数gameView();
        进入设置: 敬请期待...
        退出游戏: 调用exit(0);
    参数: void
    返回值: void
*/
void menuView();

/*
    负责人: 张三
    功能: gameView_ShowMap: 根据map数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowMap();

/*
    负责人: 张三
    功能: winView: 根据flag的值  打印游戏胜利界面  用户可以按任意键回到主菜单
    参数: void
    返回值: void
*/
void winView();

/*
    *难点2
    负责人: 张三
    功能: gameView: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowMap())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
*/
void gameView();
// -------------------- view --------------------

#ifndef _WIN32
// 新增辅助函数，禁止字符回显
void disableEcho();

// 新增辅助函数，允许字符回显
void enableEcho();
#endif
// 新增辅助函数，获取单个字符（包括空白字符）
char getChar();

#endif //TURINGINSTITUTE_GOBANG_H
