#pragma once
#include <windows.h>
#include <iostream>
#include <ctime>
#include <conio.h>

class TetrisBlock
{
private:
	struct BLOCK			// ����ṹ��
	{
		int iShape;			// ������״
		int iWidth;			// ������ο��
		int iDirection;		// ���鷽��
		int iColor;			// ������ɫ
		int iX;				// �����ڵ�ͼ�еĺ�����
		int iY;				// �����ڵ�ͼ�е�������
		int *pMatrix;		// �������
		BLOCK () 
			: iShape(0), iWidth(0), iDirection(0), iColor(0), iX(0), iY(0), pMatrix(NULL)
		{
		}
	};

private:
	static int *pSrcBlocks;	// ��������
	enum Color{black, blue, green, ǳ��ɫ, red, purple, yellow, white, gray, ����ɫ, ����ɫ, ǳ����ɫ, ����ɫ, ����ɫ, ����ɫ, ����ɫ};

private:
	BLOCK *pBlock;			// ��ǰ�����
	BLOCK *pNextBlock;		// ��һ������

public:
	TetrisBlock();
	void makeBlock(BLOCK *&pBlock);					// ����һ������
	void spinBlock(BLOCK *pBlock = NULL);			// ��ת����
	void printBlock(const BLOCK *pBlock = NULL);	// ���Ʒ���
	void printNextBlock();							// ������һ������
	void gotoXY(int x, int y);						// ʹ����ƶ���ָ��λ��
	void setTextColor(int iFrColor = Color::black, int iBkColor = Color::purple);	// ����������ɫ
	void clearBlock(const BLOCK *pBlock = NULL);	// �������
	void moveDown(int x = 1);						// ����������x����Ԫ
	void moveLeft(int x = 1);						// ����������x����Ԫ
	void moveRight(int x = 1);						// ����������x����Ԫ
	void spin(int x = 1);							// ������˳ʱ����תx*90��
	void getFocus();								// ������뽹��
	virtual ~TetrisBlock();
};

