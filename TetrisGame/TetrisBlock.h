#pragma once
#include <windows.h>
#include <iostream>
#include <ctime>

class TetrisBlock
{
private:
	struct BLOCK			// 方块结构体
	{
		int iShape;			// 方块形状
		int iWidth;			// 方块矩形宽度
		int iDirection;		// 方块方向
		int iColor;			// 方块颜色
		int iX;				// 方块在地图中的横坐标
		int iY;				// 方块在地图中的纵坐标
		int *pMatrix;		// 方块矩阵
		BLOCK () 
			: iShape(0), iWidth(0), iDirection(0), iColor(0), iX(0), iY(0), pMatrix(NULL)
		{
		}
	};

private:
	static int *pSrcBlocks;	// 方块矩阵库

private:
	BLOCK *pBlock;			// 当前方块结
	BLOCK *pNextBlock;		// 下一个方块

public:
	TetrisBlock();
	void makeBlock(BLOCK *&pBlock);					// 产生一个方块
	void spinBlock(BLOCK *pBlock = NULL);			// 旋转方块
	void printBlock(const BLOCK *pBlock = NULL);	// 绘制方块
	void printNextBlock();							// 绘制下一个方块
	void gotoXY(int x, int y);						// 使光标移动到指定位置
	void clearBlock(const BLOCK *pBlock = NULL);	// 清除方块
	void moveDown(int x = 1);						// 下一x个单元

	virtual ~TetrisBlock();
};

