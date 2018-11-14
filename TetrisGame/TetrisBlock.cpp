#include "TetrisBlock.h"

int *TetrisBlock::pSrcBlocks = new int [2 * 2 + 5 * 3 * 3 + 4 * 4]{	1, 1, 1, 1,	0, 0, 0, 0, 1, 0,
	1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0,	1, 0, 0, 1, 1, 0,
	0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,
};
// �������ܣ�����TetrisBlock����
// �������ƣ�TetrisBlock
// ���������
//		��
// ���������
//		��
// ������ڣ�2018-11-14
TetrisBlock::TetrisBlock()
{
	pBlock = new BLOCK;
	pNextBlock = new BLOCK;
	srand(time(NULL));
	makeBlock(pBlock);
	makeBlock(pNextBlock);
}

// �������ܣ�����һ������
// �������ƣ�makeBlock
// ���������
//		pBlock������ṹ��
// ���������
//		��
// ������ڣ�2018-11-14
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

// �������ܣ�˳ʱ����ת90��
// �������ƣ�spinBlock
// ���������
//		pBlock������ṹ��
// ���������
//		��
// ������ڣ�2018-11-14
void TetrisBlock::spinBlock(BLOCK * pBlock)
{
	// ����˹������ת
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

// �������ܣ����Ʒ���
// �������ƣ�printBlock
// ���������
//		pBlock������ṹ��
// ���������
//		��
// ������ڣ�2018-11-14
void TetrisBlock::printBlock(const BLOCK *pBlock)
{
	if (pBlock == NULL)
		pBlock = this->pBlock;

	// ��ӡ����˹����
	for (int i = 0; i < pBlock->iWidth; i++)
	{
		for (int j = 0; j < pBlock->iWidth; j++)
		{
			if (pBlock->pMatrix[i * pBlock->iWidth + j] == 1)
			{
				gotoXY((pBlock->iX + j) * 2, pBlock->iY + i);
				std::cout << "��";
			}
			else
			{
				gotoXY((pBlock->iX + j) * 2, pBlock->iY + i);
				std::cout << "��";
			}
		}
	}
	gotoXY(-1, -1);
}

// �������ܣ�������һ������
// �������ƣ�printNextBlock
// ���������
//		��
// ���������
//		��
// ������ڣ�2018-11-14
void TetrisBlock::printNextBlock()
{
	printBlock(this->pNextBlock);
}

// �������ܣ�ʹ����ƶ���ָ��λ��
// �������ƣ�gotoXY
// ���������
//		x��������
//		y��������
// ���������
//		��
// ������ڣ�2018-11-14
void TetrisBlock::gotoXY(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, { (short)x, (short)y });
}

// �������ܣ��������
// �������ƣ�clearBlock
// ���������
//		pBlock������ṹ��
// ���������
//		��
// ������ڣ�2018-11-14
void TetrisBlock::clearBlock(const BLOCK * pBlock)
{
	if (pBlock == NULL)
		pBlock = this->pBlock;

	// ��ӡ����˹����
	for (int i = 0; i < pBlock->iWidth; i++)
	{
		for (int j = 0; j < pBlock->iWidth; j++)
		{
			if (pBlock->pMatrix[i * pBlock->iWidth + j] == 1)
			{
				gotoXY((pBlock->iX + j) * 2, pBlock->iY + i);
				std::cout << "��";
			}
		}
	}
	gotoXY(-1, -1);
}

// �������ܣ������������ƶ�x����λ
// �������ƣ�moveDown
// ���������
//		x���ƶ�����
// ���������
//		��
// ������ڣ�2018-11-14
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
