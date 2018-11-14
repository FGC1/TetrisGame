#pragma once
#include <windows.h>
#include <iostream>
#include <ctime>

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
	void clearBlock(const BLOCK *pBlock = NULL);	// �������
	void moveDown(int x = 1);						// ��һx����Ԫ

	virtual ~TetrisBlock();
};

