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
	pBlock = new BLOCK;
	pNextBlock = new BLOCK;
	srand(time(NULL));
	makeBlock(pBlock);
	makeBlock(pNextBlock);
}

// 函数功能：产生一个方块
// 函数名称：makeBlock
// 输入参数：
//		pBlock：方块结构体
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::makeBlock(BLOCK *&pBlock)
{
	int iOffset = 0;

	if (pBlock == NULL)
		pBlock = new BLOCK();
	else
		delete[] pBlock->pMatrix;

	pBlock->iShape = rand() % 7;
	pBlock->iDirection = rand() % 4;

	switch (pBlock->iShape)
	{
		case 0:
			pBlock->iWidth = 2;
			iOffset = 0;
			break;
		case 1:	case 2:	case 3:	case 4:	case 5:
			pBlock->iWidth = 3;
			iOffset = 2 * 2 + (pBlock->iShape - 1) * pBlock->iWidth * pBlock->iWidth;
			break;
		case 6:
			pBlock->iWidth = 4;
			iOffset = 2 * 2 + (pBlock->iShape - 1) * 3 * 3;
			break;
		default:
			break;
	}
	pBlock->pMatrix = new int[pBlock->iWidth * pBlock->iWidth];
	memcpy(pBlock->pMatrix, pSrcBlocks + iOffset, pBlock->iWidth * pBlock->iWidth * sizeof(int));
}

// 函数功能：顺时针旋转90°
// 函数名称：spinBlock
// 输入参数：
//		pBlock：方块结构体
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::spinBlock(BLOCK * pBlock)
{
	// 俄罗斯方块旋转
	if (pBlock == NULL)
		pBlock = this->pBlock;
	int *tmpBlock = new int[pBlock->iWidth * pBlock->iWidth];
	for (int i = 0; i < pBlock->iWidth; i++)
	{
		for (int j = 0; j < pBlock->iWidth; j++)
		{
			int x = pBlock->iWidth - j - 1;
			int y = i;
			tmpBlock[i * pBlock->iWidth + j] = pBlock->pMatrix[x * pBlock->iWidth + y];
		}
	}
	memcpy(pBlock->pMatrix, tmpBlock, pBlock->iWidth * pBlock->iWidth * sizeof(int));
	delete[] tmpBlock;
	
}

// 函数功能：绘制方块
// 函数名称：printBlock
// 输入参数：
//		pBlock：方块结构体
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::printBlock(const BLOCK *pBlock)
{
	if (pBlock == NULL)
		pBlock = this->pBlock;

	// 打印俄罗斯方块
	for (int i = 0; i < pBlock->iWidth; i++)
	{
		for (int j = 0; j < pBlock->iWidth; j++)
		{
			if (pBlock->pMatrix[i * pBlock->iWidth + j] == 1)
			{
				gotoXY((pBlock->iX + j) * 2, pBlock->iY + i);
				std::cout << "■";
			}
			else
			{
				gotoXY((pBlock->iX + j) * 2, pBlock->iY + i);
				std::cout << "□";
			}
		}
	}
	gotoXY(-1, -1);
}

// 函数功能：绘制下一个方块
// 函数名称：printNextBlock
// 输入参数：
//		无
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::printNextBlock()
{
	printBlock(this->pNextBlock);
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

// 函数功能：清除方块
// 函数名称：clearBlock
// 输入参数：
//		pBlock：方块结构体
// 输出参数：
//		无
// 完成日期：2018-11-14
void TetrisBlock::clearBlock(const BLOCK * pBlock)
{
	if (pBlock == NULL)
		pBlock = this->pBlock;

	// 打印俄罗斯方块
	for (int i = 0; i < pBlock->iWidth; i++)
	{
		for (int j = 0; j < pBlock->iWidth; j++)
		{
			if (pBlock->pMatrix[i * pBlock->iWidth + j] == 1)
			{
				gotoXY((pBlock->iX + j) * 2, pBlock->iY + i);
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
	pBlock->iY += x;
	printBlock();
}

TetrisBlock::~TetrisBlock()
{
	delete[] pBlock->pMatrix;
	delete[] pNextBlock->pMatrix;
	delete pBlock;
	delete pNextBlock;
}
