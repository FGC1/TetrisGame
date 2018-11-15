#pragma once
#include <windows.h>
#include <iostream>
#include <ctime>
#include <conio.h>

class TetrisBlock
{
private:
	static int *pSrcBlocks;	// ��������
	enum Color{black, blue, green, ǳ��ɫ, red, purple, yellow, white, gray, ����ɫ, ����ɫ, ǳ����ɫ, ����ɫ, ����ɫ, ����ɫ, ����ɫ};

private:
	int iShape;			// ������״
	int iWidth;			// ������ο��
	int iDirection;		// ���鷽��
	int iColor;			// ������ɫ
	int iX;				// �����ڵ�ͼ�еĺ�����
	int iY;				// �����ڵ�ͼ�е�������
	int *pMatrix;		// �������

public:
	TetrisBlock();
	void makeBlock();								// ����һ������
	void spinBlock();								// ��ת����
	void printBlock();								// ���Ʒ���
	void gotoXY(int x, int y);						// ʹ����ƶ���ָ��λ��
	void setTextColor(int iFrColor = Color::black, int iBkColor = Color::purple);	// ����������ɫ
	void clearBlock();								// �������
	void moveDown(int x = 1);						// ����������x����Ԫ
	void moveLeft(int x = 1);						// ����������x����Ԫ
	void moveRight(int x = 1);						// ����������x����Ԫ
	void spin(int x = 1);							// ������˳ʱ����תx*90��
	void getFocus();								// ������뽹��
	virtual ~TetrisBlock();
};

