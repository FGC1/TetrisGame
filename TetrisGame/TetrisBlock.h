#pragma once
#include <windows.h>
#include <iostream>
#include <ctime>
#include <conio.h>

class TetrisBlock
{
private:
	static int *pSrcBlocks;	// 方块矩阵库
	enum Color{black, blue, green, 浅绿色, red, purple, yellow, white, gray, 淡蓝色, 淡绿色, 浅淡绿色, 淡红色, 淡紫色, 淡黄色, 亮白色};

private:
	int iShape;			// 方块形状
	int iWidth;			// 方块矩形宽度
	int iDirection;		// 方块方向
	int iColor;			// 方块颜色
	int iX;				// 方块在地图中的横坐标
	int iY;				// 方块在地图中的纵坐标
	int *pMatrix;		// 方块矩阵

public:
	TetrisBlock();
	void makeBlock();								// 产生一个方块
	void spinBlock();								// 旋转方块
	void printBlock();								// 绘制方块
	void gotoXY(int x, int y);						// 使光标移动到指定位置
	void setTextColor(int iFrColor = Color::black, int iBkColor = Color::purple);	// 设置字体颜色
	void clearBlock();								// 清除方块
	void moveDown(int x = 1);						// 将方块下移x个单元
	void moveLeft(int x = 1);						// 将方块左移x个单元
	void moveRight(int x = 1);						// 将方块右移x个单元
	void spin(int x = 1);							// 将方块顺时针旋转x*90度
	void getFocus();								// 获得输入焦点
	virtual ~TetrisBlock();
};

