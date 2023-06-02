#include "chess.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#pragma warning(disable:4996)

// Definicia globalnej sachovnice
int chessboard[L][L];

// Funkcia na vykreslenie sachovnice (pracuje s globalnou sachovnicou)
void print_chessboard()
{


	//init_chessboard();
	int i, j;
	printf("             CIERNY   \n\n");
	for (i = L;i>0;i--)
	{
		printf("%d   ", i);
		for (j = 1;j<=L;j++)
		{
			if (chessboard[i][j] == B_PAWN) { printf("[p]"); }
			else if (chessboard[i][j] == B_ROOK) { printf("[v]"); }
			else if (chessboard[i][j] == B_KNIGHT) { printf("[j]"); }
			else if (chessboard[i][j] == B_BISHOP) { printf("[s]"); }
			else if (chessboard[i][j] == B_QUEEN) { printf("[d]"); }
			else if (chessboard[i][j] == B_KING) { printf("[k]"); }
			else if (chessboard[i][j] == W_PAWN) { printf("[P]"); }
			else if (chessboard[i][j] == W_ROOK) { printf("[V]"); }
			else if (chessboard[i][j] == W_KNIGHT) { printf("[J]"); }
			else if (chessboard[i][j] == W_BISHOP) { printf("[S]"); }
			else if (chessboard[i][j] == W_QUEEN) { printf("[D]"); }
			else if (chessboard[i][j] == W_KING) { printf("[K]"); }
			else if (chessboard[i][j] == EMPTY_SQUARE) { printf("[ ]"); }
		}
		printf("\n");
	}
	printf("\n     a  b  c  d  e  f  g  h\n");
	printf("\n             BIELY  \n\n");

}

// Funkcia na pociatocne rozostavenie figurok na sachovnici
void init_chessboard()
{
	int i,j;

	for (i = L;i > 0;i--)  //najprv vyplnim prazdnymi
	{
		for (j = 1;j <= L;j++)
		{
			chessboard[j][i] = EMPTY_SQUARE;
		}
	}

	for (i = L;i > 0;i--) //pridam PAWNS
	{
		chessboard[7][i] = B_PAWN;
		chessboard[2][i] = W_PAWN;
	}

	chessboard[1][1] = W_ROOK; //biela strana
	chessboard[1][8] = W_ROOK;
	chessboard[1][2] = W_KNIGHT;
	chessboard[1][7] = W_KNIGHT;
	chessboard[1][3] = W_BISHOP;
	chessboard[1][6] = W_BISHOP;
	chessboard[1][4] = W_QUEEN;
	chessboard[1][5] = W_KING;

	chessboard[8][1] = B_ROOK; //cierna strana
	chessboard[8][8] = B_ROOK;
	chessboard[8][2] = B_KNIGHT;
	chessboard[8][7] = B_KNIGHT;
	chessboard[8][3] = B_BISHOP;
	chessboard[8][6] = B_BISHOP;
	chessboard[8][4] = B_QUEEN;
	chessboard[8][5] = B_KING;
}

// Funkcia, ktora overi tah figurkou [srow,scol]-->[trow,tcol] a v pripade,
// ze je platny, tak ho aj zrealizuje.
//
// VSTUP:
//      srow - riadok povodneho policka
//      scol - stlpec povodneho policka
//      trow - riadok noveho policka
//      tcol - stlpec noveho policka
//      p_id - ID hraca (pozri chess.h)
//
// VYSTUP:
//      V pripade platneho/zrealizovaneho tahu funkcia vrati 1.
//      V pripade, ze bol tah neplatny funkcia vrati 0.

int pohyb(p_id) //funkcia ktora spravi vsetko pre urciteho hraca
{
	int srow, scol, trow, tcol;
	char scolch, tcolch;
	if (p_id == WHITE_PLAYER_ID) { printf("BIELY JE NA RADE : "); } //aby vedel kto je na rade
	if (p_id == BLACK_PLAYER_ID) { printf("CIERNY JE NA RADE : "); }
	scanf("%1d", &srow); //ratam s tym ze clovek nie je hlupy a fakt zada to pismeno
	scanf("%1c", &scolch);
	scol = (int) (scolch) - 96; //prevadzam pomcou ASCII
	scanf("%1d", &trow); //ratam s tym ze clovek nie je hlupy a fakt zada to pismeno
	scanf("%1c", &tcolch);
	tcol = (int)(tcolch)-96;
	move(srow,scol,trow,tcol,p_id);

}

int move(int srow, int scol, int trow, int tcol, int p_id) // funkcia ktora inicializuje pohyb hraca
{
	if (srow > L || srow<0 || scol>L || scol<0 || trow>L || trow<0 || tcol>L || tcol < 0)
	{
		printf("MIMO POLA\n"); //keby nahodou bola aspon jedna zo suradnic mimo pola
		return 0;
	}
	if (chessboard[srow][scol] == EMPTY_SQUARE) 
	{
		printf("ZIADEN PANAK\n"); //nevybral ziadneho panaka
		return 0;
	}
	if (((p_id == WHITE_PLAYER_ID) && (chessboard[srow][scol] < 0)) || ((p_id == BLACK_PLAYER_ID) && (chessboard[srow][scol] > 0)))
	{
		printf("NIE JE TO TVOJ PANAK\n"); // keby nahodou vybral zleho panaka
		return 0;
	}
	if ((srow == trow) && (scol == tcol))
	{
		printf("ROVNAKA POLOHA\n");
		return 0;
	}
	if ((chessboard[srow][scol] == B_PAWN) || (chessboard[srow][scol] == W_PAWN)){if ((kontrolaPawn(srow, scol, trow, tcol, p_id)) == 1){ return 1; } } //kontrolaPesiaka ak vyje pohyb,vrati 1
	if ((chessboard[srow][scol] == B_ROOK) || (chessboard[srow][scol] == W_ROOK)){if ((kontrolaRook(srow, scol, trow, tcol, p_id)) == 1){ return 1; } }
	if ((chessboard[srow][scol] == B_KNIGHT) || (chessboard[srow][scol] == W_KNIGHT)) { if ((kontrolaKnight(srow, scol, trow, tcol, p_id)) == 1) { return 1; } }
	if ((chessboard[srow][scol] == B_BISHOP) || (chessboard[srow][scol] == W_BISHOP)) { if ((kontrolaBishop(srow, scol, trow, tcol, p_id)) == 1) { return 1; } }
	if ((chessboard[srow][scol] == B_QUEEN) || (chessboard[srow][scol] == W_QUEEN)) { if ((kontrolaQueen(srow, scol, trow, tcol, p_id)) == 1) { return 1; } }
	if ((chessboard[srow][scol] == B_KING) || (chessboard[srow][scol] == W_KING)) { if ((kontrolaKing(srow, scol, trow, tcol, p_id)) == 1) { return 1; } }

    return 0; // tento riadok je tu len kvoli kompilacii
}


int kontrolaPawn(int srow, int scol, int trow, int tcol,int p_id)
{
	if ((p_id == WHITE_PLAYER_ID) && (srow == 2) && (trow == srow + 2) && (scol == tcol)) //prvy pohyb je mozne o dva
	{
		chessboard[trow][tcol] = W_PAWN;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if ((p_id == BLACK_PLAYER_ID) && (srow == 7) && (trow == srow - 2)&& (scol == tcol))
	{
		chessboard[trow][tcol] = B_PAWN;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}

	if ((p_id == WHITE_PLAYER_ID) && (trow == srow + 1) && (scol == tcol) && (chessboard[trow][tcol] == EMPTY_SQUARE)) //moze ist o jedno dopredu ale to musi byt prazdne
	{
		chessboard[trow][tcol] = W_PAWN;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if ((p_id == BLACK_PLAYER_ID) && (trow == srow - 1) && (scol == tcol) && (chessboard[trow][tcol] == EMPTY_SQUARE)) 
	{
		chessboard[trow][tcol] = B_PAWN;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}

	if ((p_id == WHITE_PLAYER_ID) && (trow == srow + 1) && (scol == tcol) && (chessboard[trow][tcol] != EMPTY_SQUARE)) //moze ist o jedno dopredu ale to musi byt prazdne
	{
		return 0;
	}
	if ((p_id == BLACK_PLAYER_ID) && (trow == srow - 1) && (scol == tcol) && (chessboard[trow][tcol] != EMPTY_SQUARE))
	{
		return 0;
	}

	if ((p_id == WHITE_PLAYER_ID) && (trow = srow + 1) && (chessboard[trow][tcol] < 0) && ((tcol = scol + 1) || (tcol = scol - 1))) //vyhadzovanie panakov
	{
		chessboard[trow][tcol] = W_PAWN;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if ((p_id == BLACK_PLAYER_ID) && (trow = srow - 1) && (chessboard[trow][tcol] > 0) && ((tcol = scol + 1) || (tcol = scol - 1))) //vyhadzovanie panakov
	{
		chessboard[trow][tcol] = B_PAWN;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	return 0;
}

int kontrolaRook(int srow, int scol, int trow, int tcol, int p_id)
{
	int i;
	if (((srow == trow) && (scol != tcol)) && (chessboard[trow][tcol] <= 0)&& (p_id==WHITE_PLAYER_ID)) //ktory kolvek rad alebo stlpec kde stoji okrem kde su obsadene jej tymom JE TO BLBOST ALE UVEDOMIL SOM SI TO NESKORO
	{
		if (tcol > scol) //nesmie prechadzat cez inych panakov ale nekontroluje seba sameho, preto to +1
		{
			for (i = scol+1;i < tcol;i++)
			{
				if (chessboard[trow][i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if (scol > tcol) //nesmie prechadzat cez inych panakov
		{
			for (i = scol-1;i > tcol;i--)
			{
				if (chessboard[trow][i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}
		chessboard[trow][tcol] = W_ROOK;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if (((srow != trow) && (scol == tcol)) && (chessboard[trow][tcol] <= 0) && (p_id == WHITE_PLAYER_ID)) //ktory kolvek rad alebo stlpec kde stoji okrem kde su obsadene jej tymom
	{
		if (trow > srow) //nesmie prechadzat cez inych panakov
		{
			for (i = srow+1;i < trow;i++)
			{
				if (chessboard[i][scol] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if (srow > trow) //nesmie prechadzat cez inych panakov
		{
			for (i = srow-1;i > trow;i--)
			{
				if (chessboard[i][scol] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}
		chessboard[trow][tcol] = W_ROOK;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}

	if (((srow == trow) && (scol != tcol)) && (chessboard[trow][tcol] >= 0) && (p_id == BLACK_PLAYER_ID)) //ktory kolvek rad alebo stlpec kde stoji okrem kde su obsadene jej tymom
	{
		if (tcol > scol) //nesmie prechadzat cez inych panakov
		{
			for (i = scol+1;i < tcol;i++)
			{
				if (chessboard[trow][i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if (scol > tcol) //nesmie prechadzat cez inych panakov
		{
			for (i = scol-1;i > tcol;i--)
			{
				if (chessboard[trow][i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}
		chessboard[trow][tcol] = B_ROOK;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if (((srow != trow) && (scol == tcol)) && (chessboard[trow][tcol] >= 0) && (p_id == BLACK_PLAYER_ID)) //ktory kolvek rad alebo stlpec kde stoji okrem kde su obsadene jej tymom
	{
		if (trow > srow) //nesmie prechadzat cez inych panakov
		{
			for (i = srow+1;i < trow;i++)
			{
				if (chessboard[i][scol] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}
		if (srow > trow) //nesmie prechadzat cez inych panakov
		{
			for (i = srow-1;i > trow;i--)
			{
				if (chessboard[i][scol] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}
		chessboard[trow][tcol] = B_ROOK;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	return 0;
}

int kontrolaKnight(int srow, int scol, int trow, int tcol, int p_id)
{
	if (((trow == srow + 2) && ((tcol == scol + 1) || (tcol == scol - 1)))&&(p_id==WHITE_PLAYER_ID))
	{
		if ((p_id == WHITE_PLAYER_ID)&&(chessboard[trow][tcol]>0)){return 0;} //pokial skace na svojho,neskoci
		chessboard[trow][tcol] = W_KNIGHT;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if (((trow == srow - 2) && ((tcol == scol + 1) || (tcol == scol - 1))) && (p_id == WHITE_PLAYER_ID))
	{
		if ((p_id == WHITE_PLAYER_ID) && (chessboard[trow][tcol] > 0)) { return 0; } //pokial skace na svojho,neskoci
		chessboard[trow][tcol] = W_KNIGHT;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if (((tcol == scol + 2) && ((trow == srow + 1) || (trow == srow - 1))) && (p_id == WHITE_PLAYER_ID))
	{
		if ((p_id == WHITE_PLAYER_ID) && (chessboard[trow][tcol] > 0)) { return 0; } //pokial skace na svojho,neskoci
		chessboard[trow][tcol] = W_KNIGHT;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if (((tcol == scol - 2) && ((trow == srow + 1) || (trow == srow - 1))) && (p_id == WHITE_PLAYER_ID))
	{
		if ((p_id == WHITE_PLAYER_ID) && (chessboard[trow][tcol] > 0)) { return 0; } //pokial skace na svojho,neskoci
		chessboard[trow][tcol] = W_KNIGHT;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}

	if (((trow == srow + 2) && ((tcol == scol + 1) || (tcol == scol - 1))) && (p_id == BLACK_PLAYER_ID))
	{
		if ((p_id == WHITE_PLAYER_ID) && (chessboard[trow][tcol] < 0)) { return 0; } //pokial skace na svojho,neskoci
		chessboard[trow][tcol] = B_KNIGHT;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if (((trow == srow - 2) && ((tcol == scol + 1) || (tcol == scol - 1))) && (p_id == BLACK_PLAYER_ID))
	{
		if ((p_id == WHITE_PLAYER_ID) && (chessboard[trow][tcol] < 0)) { return 0; } //pokial skace na svojho,neskoci
		chessboard[trow][tcol] = B_KNIGHT;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if (((tcol == scol + 2) && ((trow == srow + 1) || (trow == srow - 1))) && (p_id == BLACK_PLAYER_ID))
	{
		if ((p_id == WHITE_PLAYER_ID) && (chessboard[trow][tcol] < 0)) { return 0; } //pokial skace na svojho,neskoci
		chessboard[trow][tcol] = B_KNIGHT;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if (((tcol == scol - 2) && ((trow == srow + 1) || (trow == srow - 1))) && (p_id == BLACK_PLAYER_ID))
	{
		if ((p_id == WHITE_PLAYER_ID) && (chessboard[trow][tcol] < 0)) { return 0; } //pokial skace na svojho,neskoci
		chessboard[trow][tcol] = B_KNIGHT;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	return 0;
}

int kontrolaBishop(int srow, int scol, int trow, int tcol, int p_id)
{
	int i;
	if (abs(trow - srow) == abs( tcol - scol))  //kontrola aby niekoho nepreskocil,nemoze preskocit ani nepriatelov
	{
		if ((trow < srow) && (tcol < scol))
		{
			for (i=1;i<=abs(trow-srow);i++)
			{
				if (chessboard[srow - i][scol - 1] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if ((trow > srow) && (tcol > scol))
		{
			for (i = 1;i <= abs(trow - srow);i++)
			{
				if (chessboard[srow + i][scol + i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if ((trow < srow) && (tcol > scol))
		{
			for (i = 1;i <= abs(trow - srow);i++)
			{
				if (chessboard[srow - i][scol + i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if ((trow > srow) && (tcol < scol))
		{
			for (i = 1;i <= abs(trow - srow);i++)
			{
				if (chessboard[srow + i][scol - i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if (p_id == WHITE_PLAYER_ID)  //samotny pohyb
		{
			chessboard[trow][tcol] = W_BISHOP;
			chessboard[srow][scol] = EMPTY_SQUARE;
			return 1;
		}
		if (p_id == BLACK_PLAYER_ID)
		{
			chessboard[trow][tcol] = B_BISHOP;
			chessboard[srow][scol] = EMPTY_SQUARE;
			return 1;
		}
	}
}

int kontrolaQueen(int srow, int scol, int trow, int tcol, int p_id)
{
	int i;
	if (abs(trow - srow) == abs(tcol - scol))  //kontrola od veze(diagonaly)

	{
		if ((trow < srow) && (tcol < scol))
		{
			for (i = 1;i <= abs(trow - srow);i++)
			{
				if (chessboard[srow - i][scol - 1] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if ((trow > srow) && (tcol > scol))
		{
			for (i = 1;i <= abs(trow - srow);i++)
			{
				if (chessboard[srow + i][scol + i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if ((trow < srow) && (tcol > scol))
		{
			for (i = 1;i <= abs(trow - srow);i++)
			{
				if (chessboard[srow - i][scol + i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if ((trow > srow) && (tcol < scol))
		{
			for (i = 1;i <= abs(trow - srow);i++)
			{
				if (chessboard[srow + i][scol - i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if (p_id == WHITE_PLAYER_ID)  //samotny pohyb
		{
			chessboard[trow][tcol] = W_QUEEN;
			chessboard[srow][scol] = EMPTY_SQUARE;
			return 0;
		}
		if (p_id == BLACK_PLAYER_ID)
		{
			chessboard[trow][tcol] = B_QUEEN;
			chessboard[srow][scol] = EMPTY_SQUARE;
			return 0;
		}
	}
	if (((srow == trow) && (scol != tcol)) && (chessboard[trow][tcol] <= 0) && (p_id == WHITE_PLAYER_ID)) //ktory kolvek rad alebo stlpec kde stoji okrem kde su obsadene jej tymom JE TO BLBOST ALE UVEDOMIL SOM SI TO NESKORO
	{
		if (tcol > scol) //nesmie prechadzat cez inych panakov ale nekontroluje seba sameho, preto to +1
		{
			for (i = scol + 1;i < tcol;i++)
			{
				if (chessboard[trow][i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if (scol > tcol) //nesmie prechadzat cez inych panakov
		{
		for (i = scol - 1;i > tcol;i--)
		{
			if (chessboard[trow][i] != EMPTY_SQUARE)
			{
				return 0;
			}
		}
		}
		chessboard[trow][tcol] = W_QUEEN;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 0;
	}
	if (((srow != trow) && (scol == tcol)) && (chessboard[trow][tcol] <= 0) && (p_id == WHITE_PLAYER_ID)) //ktory kolvek rad alebo stlpec kde stoji okrem kde su obsadene jej tymom
	{
		if (trow > srow) //nesmie prechadzat cez inych panakov
		{
			for (i = srow + 1;i < trow;i++)
			{
				if (chessboard[i][scol] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if (srow > trow) //nesmie prechadzat cez inych panakov
		{
			for (i = srow - 1;i > trow;i--)
			{
				if (chessboard[i][scol] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}
		chessboard[trow][tcol] = W_QUEEN;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}

	if (((srow == trow) && (scol != tcol)) && (chessboard[trow][tcol] >= 0) && (p_id == BLACK_PLAYER_ID)) //ktory kolvek rad alebo stlpec kde stoji okrem kde su obsadene jej tymom
	{
		if (tcol > scol) //nesmie prechadzat cez inych panakov
		{
			for (i = scol + 1;i < tcol;i++)
			{
				if (chessboard[trow][i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}

		if (scol > tcol) //nesmie prechadzat cez inych panakov
		{
			for (i = scol - 1;i > tcol;i--)
			{
				if (chessboard[trow][i] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}
		chessboard[trow][tcol] = B_QUEEN;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if (((srow != trow) && (scol == tcol)) && (chessboard[trow][tcol] >= 0) && (p_id == BLACK_PLAYER_ID)) //ktory kolvek rad alebo stlpec kde stoji okrem kde su obsadene jej tymom
	{
		if (trow > srow) //nesmie prechadzat cez inych panakov
		{
			for (i = srow + 1;i < trow;i++)
			{
				if (chessboard[i][scol] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}
		if (srow > trow) //nesmie prechadzat cez inych panakov
		{
			for (i = srow - 1;i > trow;i--)
			{
				if (chessboard[i][scol] != EMPTY_SQUARE)
				{
					return 0;
				}
			}
		}
		chessboard[trow][tcol] = B_QUEEN;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	return 0;
}

int kontrolaKing(int srow, int scol, int trow, int tcol, int p_id)
{
	if ((trow - srow > 1) || ( tcol - scol > 1)) //kral sa moze hybat len o jedno
	{
	return 0;
	}
	if ((p_id == WHITE_PLAYER_ID) && (chessboard[trow][tcol] > 0)) //aby neskocil na svojich
	{
		return 0;
	}
	if ((p_id == BLACK_PLAYER_ID) && (chessboard[trow][tcol] < 0)) //aby neskocil na svojich
	{
		return 0;
	}
	if (p_id == WHITE_PLAYER_ID)
	{
		chessboard[trow][tcol] = W_KING;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}
	if (p_id == BLACK_PLAYER_ID)
	{
		chessboard[trow][tcol] = B_KING;
		chessboard[srow][scol] = EMPTY_SQUARE;
		return 1;
	}

}