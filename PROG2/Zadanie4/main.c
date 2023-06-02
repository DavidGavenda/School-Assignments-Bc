#include <stdio.h>
#include "chess.h"
#pragma warning(disable:4996)

int main()
{
	init_chessboard();
	while (1 == 1)
	{
		do {
			print_chessboard();
		} while (pohyb(WHITE_PLAYER_ID) == 0);
		do {
			print_chessboard();
		} while (pohyb(BLACK_PLAYER_ID) == 0);
	}
	getchar();
    return 0;
}
