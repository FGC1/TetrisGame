#include <iostream>
#include <ctime>
#include "TetrisBlock.h"

using namespace std;

int main()
{	
	TetrisBlock tetrisBlock;
	tetrisBlock.printBlock();
	cout << endl;
	tetrisBlock.printNextBlock();
	
	while (cin.get() != 'q')
	{
		tetrisBlock.moveDown();
	}
	cin.get();
	return 0;
}