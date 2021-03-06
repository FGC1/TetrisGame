#include "TetrisBlock.h"

int *TetrisBlock::pSrcBlocks = new int [2 * 2 + 5 * 3 * 3 + 4 * 4]{	1, 1, 1, 1,	0, 0, 0, 0, 1, 0,
	1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0,	1, 0, 0, 1, 1, 0,
	0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,
};
// 函数功能：构造TetrisBlock对象
// 函数名称：TetrisBlock
// 输入参数：
//		无
// 输出参数：
//		无
// 完成日期：2018-11-14
TetrisBlock::TetrisBlock()
{
	pMatrix = NULL;
	srand(time(NULL));
	makeBlock();
}

// 函数功能：产生一个方块
// 函数名称：makeBlock
// 输入参数：
//		无
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::makeBlock()
{
	int iOffset = 0;

	iShape = rand() % 7;
	iDirection = rand() % 4;

	switch (iShape)
	{
		case 0:
			iWidth = 2;
			iOffset = 0;
			break;
		case 1:	case 2:	case 3:	case 4:	case 5:
			iWidth = 3;
			iOffset = 2 * 2 + (iShape - 1) * iWidth * iWidth;
			break;
		case 6:
			iWidth = 4;
			iOffset = 2 * 2 + (iShape - 1) * 3 * 3;
			break;
		default:
			break;
	}
	pMatrix = new int[iWidth * iWidth];
	memcpy(pMatrix, pSrcBlocks + iOffset, iWidth * iWidth * sizeof(int));
}

// 函数功能：顺时针旋转90°
// 函数名称：spinBlock
// 输入参数：
//		无
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::spinBlock()
{
	int *tmpBlock = new int[iWidth * iWidth];
	for (int i = 0; i < iWidth; i++)
	{
		for (int j = 0; j < iWidth; j++)
		{
			int x = iWidth - j - 1;
			int y = i;
			tmpBlock[i * iWidth + j] = pMatrix[x * iWidth + y];
		}
	}
	memcpy(pMatrix, tmpBlock, iWidth * iWidth * sizeof(int));
	delete[] tmpBlock;
	
}

// 函数功能：绘制方块
// 函数名称：printBlock
// 输入参数：
//		无
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::printBlock()
{
	for (int i = 0; i < iWidth; i++)
	{
		for (int j = 0; j < iWidth; j++)
		{
			if (pMatrix[i * iWidth + j] == 1)
			{
				setTextColor(Color::淡黄色, Color::purple);
				gotoXY((iX + j) * 2, iY + i);
				std::cout << "■";
			}
			else
			{
				setTextColor(Color::gray, Color::purple);
				gotoXY((iX + j) * 2, iY + i);
				std::cout << "□";
			}
		}
	}
	gotoXY(-1, -1);
}

// 函数功能：使光标移动到指定位置
// 函数名称：gotoXY
// 输入参数：
//		x：横坐标
//		y：纵坐标
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::gotoXY(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, { (short)x, (short)y });
}

// 函数功能：设置字体颜色
// 函数名称：setTextColor
// 输入参数：
//		iFrColor：字体颜色
//		iBkColor：字体背景颜色
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::setTextColor(int iFrColor, int iBkColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, iFrColor + iBkColor * 0x10);
}

// 函数功能：清除方块
// 函数名称：clearBlock
// 输入参数：
//		pBlock：方块结构体
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::clearBlock()
{
	for (int i = 0; i < iWidth; i++)
	{
		for (int j = 0; j < iWidth; j++)
		{
			if (pMatrix[i * iWidth + j] == 1)
			{
				setTextColor(Color::gray, Color::purple);
				gotoXY((iX + j) * 2, iY + i);
				std::cout << "□";
			}
		}
	}
	gotoXY(-1, -1);
}

// 函数功能：将方块向下移动x个单位
// 函数名称：moveDown
// 输入参数：
//		x：移动距离
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::moveDown(int x)
{
	clearBlock();
	iY += x;
	printBlock();
}

// 函数功能：将方块向左移动x个单位
// 函数名称：moveLeft
// 输入参数：
//		x：移动距离
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::moveLeft(int x)
{
	clearBlock();
	iX -= x;
	printBlock();
}

// 函数功能：将方块向右移动x个单位
// 函数名称：moveRight
// 输入参数：
//		x：移动距离
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::moveRight(int x)
{
	clearBlock();
	iX += x;
	printBlock();
}

// 函数功能：将方块顺时针旋转x*90度
// 函数名称：spin
// 输入参数：
//		x：旋转度数/90度
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::spin(int x)
{
	clearBlock();
	spinBlock();
	--x ? spin(x) : 0;
	printBlock();
}

// 函数功能：获取输入焦点
// 函数名称：getLife
// 输入参数：
//		无
// 输出参数：
//		无
// 完成日期：2018-11-15
void TetrisBlock::getFocus()
{
	char ch = '\0';
	while (1)
	{
		while (!_kbhit());		// 检测键盘输入
		ch = _getch();			// 获取键盘输入字符
		if (ch == -32)
		{
			ch = _getch();
			switch (ch) {
				case 72:
					spin();			break;
				case 75:
					moveLeft();		break;
				case 80:
					moveDown();		break;
				case 77:
					moveRight();	break;
			}
		}
		else
		{
			switch (ch) {
				case 'w': case 'W':
					spin();			break;
				case 'a':
					moveLeft();		break;
				case 's':
					moveDown();		break;
				case 'd':
					moveRight();	break;
			}
			if (ch == 'q') break;
		}
	}
}

TetrisBlock::~TetrisBlock()
{
	delete[] pMatrix;
}
