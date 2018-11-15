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
	pMatrix = NULL;
	srand(time(NULL));
	makeBlock();
}

// �������ܣ�����һ������
// �������ƣ�makeBlock
// ���������
//		��
// ���������
//		��
// ������ڣ�2018-11-14
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

// �������ܣ�˳ʱ����ת90��
// �������ƣ�spinBlock
// ���������
//		��
// ���������
//		��
// ������ڣ�2018-11-14
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

// �������ܣ����Ʒ���
// �������ƣ�printBlock
// ���������
//		��
// ���������
//		��
// ������ڣ�2018-11-14
void TetrisBlock::printBlock()
{
	for (int i = 0; i < iWidth; i++)
	{
		for (int j = 0; j < iWidth; j++)
		{
			if (pMatrix[i * iWidth + j] == 1)
			{
				setTextColor(Color::����ɫ, Color::purple);
				gotoXY((iX + j) * 2, iY + i);
				std::cout << "��";
			}
			else
			{
				setTextColor(Color::gray, Color::purple);
				gotoXY((iX + j) * 2, iY + i);
				std::cout << "��";
			}
		}
	}
	gotoXY(-1, -1);
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

// �������ܣ�����������ɫ
// �������ƣ�setTextColor
// ���������
//		iFrColor��������ɫ
//		iBkColor�����屳����ɫ
// ���������
//		��
// ������ڣ�2018-11-14
void TetrisBlock::setTextColor(int iFrColor, int iBkColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, iFrColor + iBkColor * 0x10);
}

// �������ܣ��������
// �������ƣ�clearBlock
// ���������
//		pBlock������ṹ��
// ���������
//		��
// ������ڣ�2018-11-14
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
	iY += x;
	printBlock();
}

// �������ܣ������������ƶ�x����λ
// �������ƣ�moveLeft
// ���������
//		x���ƶ�����
// ���������
//		��
// ������ڣ�2018-11-14
void TetrisBlock::moveLeft(int x)
{
	clearBlock();
	iX -= x;
	printBlock();
}

// �������ܣ������������ƶ�x����λ
// �������ƣ�moveRight
// ���������
//		x���ƶ�����
// ���������
//		��
// ������ڣ�2018-11-14
void TetrisBlock::moveRight(int x)
{
	clearBlock();
	iX += x;
	printBlock();
}

// �������ܣ�������˳ʱ����תx*90��
// �������ƣ�spin
// ���������
//		x����ת����/90��
// ���������
//		��
// ������ڣ�2018-11-14
void TetrisBlock::spin(int x)
{
	clearBlock();
	spinBlock();
	--x ? spin(x) : 0;
	printBlock();
}

// �������ܣ���ȡ���뽹��
// �������ƣ�getLife
// ���������
//		��
// ���������
//		��
// ������ڣ�2018-11-15
void TetrisBlock::getFocus()
{
	char ch = '\0';
	while (1)
	{
		while (!_kbhit());		// ����������
		ch = _getch();			// ��ȡ���������ַ�
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
