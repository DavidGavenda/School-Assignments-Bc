/*
Meno a priezvisko:

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_du04.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(3)  Cela implementacia musi byt v tomto jednom subore.
(4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
(5)  Program musi byt kompilovatelny.
(6)  Globalne a staticke premenne su zakazane.
(7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
	 (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
	 Nemente implementacie hotovych pomocnych funkcii, ani implementacie zadanych datovych typov.
(8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
(9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
	 Testovaci kod ale nebude hodnoteny.
(10) Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>

using namespace std;

void swaper(int* a, int* b);

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Hmotnost produktu a obalu. Hmotnost zabaleneho produktu je suctom obidvoch poloziek
struct Weight {
	int product; // hmotnost produktu
	int packing; // hmotnost balenia
};

//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
	Usporiada pole 'data'.
	Pouzije algoritmus bubble sort.
	Poradie usporiadania je od najvacsieho prvku po najmensi.

	PARAMETRE:
		[in, out] data - pole, ktore funkcia usporiada
		[in] length - pocet prvkov pola

	VSTUPNA PODMIENKA:
		ak 'length' > 0, tak 'data' ukazuje na platne pole

	PRIKLADY:
		{1,3,2} -> {3, 2, 1}
		{} -> {}
*/
void bubbleSort(int* data, const size_t length) {
	// TODO
	for (size_t i = 0; i < length - 1; i++) {
		for (size_t j = 0; j < length - i - 1; j++) {
			if (data[j] < data[j + 1]) {
				swaper(data + j, data + j + 1);
			}
		}
	}

}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
	Usporiada pole 'data' podla celkovej hmotnosti zabaleneho tovaru, t.j. podla suctu poloziek (product a packing).
	Pouzije algoritmus bubble sort.
	Poradie usporiadania je od najvacsieho prvku po najmensi.

	Podmienka porovnania struktur:
	Pri porovnavani prvkov funkcia scita hodnoty product a packing oboch porovnavanych struktur.
	Struktury s vacsim suctom poloziek budu po usporiadani pred strukturami s mensim suctom poloziek.

	Vzajomne usporiadanie struktur s rovnakym suctom poloziek:
	Pri bodovom hodnoteni nezalezi na vzajomnom usporiadani struktur s rovnakym suctom poloziek (aj ked hodnoty poloziek mozu byt rozne).
	Lepsie je vsak implementovat stabilne triedenie (struktury s rovnakym suctom poloziek nemenia vzajomne usporiadanie).

	PARAMETRE:
		[in, out] data - pole, ktore funkcia usporiada
		[in] length - pocet prvkov pola

	VSTUPNA PODMIENKA:
		ak 'length' > 0, tak 'data' ukazuje na platne pole

	PRIKLADY:
		{{10, 1}, {20, 2}, {5,2}} -> {{20, 2}, {10, 1},{5,2}} pretoze 20+2=22, 10+1=11, 5+2=7 a 22 > 11 > 7
		{} -> {}

	POZNAMKA:
		Priklady jednoducheho vytvorenia pola v testovacom kode:
		Weight baliky[] = {{10, 1}, {20, 2}, {5,2}};
		Weight baliky[] = {{.product = 10, .packing = 1}, {.product = 20, .packing = 2}, {.product = 5, .packing = 2}};
*/

void bubbleSort(Weight* data, const size_t length) {
	for (size_t i = 0; i < length - 1; i++) {
		for (size_t j = 0; j < length - i - 1; j++) {
			if (data[j].packing + data[j].product < data[j + 1].packing + data[j + 1].product) {
				swaper(&data[j].packing, &data[j + 1].packing);
				swaper(&data[j].product, &data[j + 1].product);
			}
		}
	}

}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
	Vyberie pivota a vrati jeho index.
	Pivota vyberie ako median prvkov:
	  - data[low]
	  - data[(high+low)/2]
	  - data[high-1]

	PARAMETRE:
		[in] 'data' - pole, v ktoreho casti s indexami low ... high-1, funkcia vybera pivot
		[in] 'low'  - index prveho prvku casti pola, v ktorej funkcia hlada pivot
		[in] 'high' - index za poslednym prvkom casti pola, v ktorej funkcia hlada pivot

	RETURN:
		index pivota

	VSTUPNE PODMIENKY:
		'data' ukazuje na platne pole
		'low' < 'high'

	PRIKLADY:
		data: {10, 20, 2000, 30, 1000, 40, 5000, 50, 60, 70}, low: 2, high: 7 -> return 2
		data: {10, 20, 1000, 30, 2000, 40, 5000, 50, 60, 70}, low: 2, high: 7 -> return 4
		data: {10, 20, 5000, 30, 1000, 40, 2000, 50, 60, 70}, low: 2, high: 7 -> return 6

		data: {10, 20, 1000, 30, 40, 2000, 50, 5000, 60, 70}, low: 2, high: 8 -> return 5

		data: {10, 20, 1000, 2000, 30, 40, 50},               low: 2, high: 4 -> return 3
		data: {10, 20, 2000, 1000, 30, 40, 50},               low: 2, high: 4 -> return 3

		data: {10, 20, 1000, 30, 40},                         low: 2, high: 3 -> return 2
*/
size_t getPivotIndex(const int* data, const size_t low, const size_t high)
{
	size_t middle = (low + high) / 2;


	if ((data[low] < data[middle] && data[middle] < data[high - 1]) || (data[high - 1] < data[middle]) && (data[middle] < data[low])) return middle;
	else if ((data[middle] < data[low] && data[low] < data[high - 1]) || (data[high - 1] < data[low] && data[low] < data[middle])) return low;
	else return high - 1;

}


//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
	Vykona partition (cast algoritmu quick sort) a vrati novy index pivota.
	Pouzije styl algoritmu Lomuto.
	Poradie usporiadania:
		Najprv (vlavo) budu prvky vacsie alebo rovne ako pivot,
		potom pivot,
		potom (vpravo) prvky mensie ako pivot.

	PARAMETRE:
		[in, out] 'data' - pole, v ktoreho casti 'low' ... 'high'-1 bude vykonane partition
		[in] 'pivot' - index pivota (pred partition)
		[in] 'low'   - index prveho prvku casti pola, v ktorej bude vykonany partition
		[in] 'high'  - index za poslednym prvkom casti pola, v ktorej bude vykonany partition

	RETURN:
		Index pivota po vykonani partition.

	VSTUPNE PODMIENKY:
		'low' <= 'pivot' < 'high'
		(index pivota moze byt lubobolny v rozsahu 'low'...'high'-1, napriklad v pripade nahodneho vyberu)
		'data' ukazuje na platne pole

	PRIKLADY:
		1. priklad:
			vstup:  data: {10, 20, 30, 40, 50, 60, 70, 80, 90}, pivot: 5, low: 2, high: 7
			vystup: data: {10, 20, 70, 60, 50, 30, 40, 80, 90}, return 3

		2. priklad:
			vstup:  data: {10, 20, 30, 40, 50, 60, 70, 50, 80, 90}, pivot: 4, low: 2, high: 8
			vystup: data: {10, 20, 50, 60, 70, 50, 30, 40, 80, 90}, return 5
*/
size_t partition(int* data, const size_t pivot, const size_t low, const size_t high)
{

	swaper(data + pivot, data + high - 1);
	int insert_i = low;
	for (int i = low; i < high - 1; i++) {
		if (data[i] > data[high - 1]) {
			swaper(data + insert_i, data + i);
			insert_i++;
		}
	}
	swaper(data + insert_i, data + high - 1);
	return insert_i;

	/////////////NEJDE UPLNE TAK AKO MA 
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
	Usporiada cast pola 'data' (s indexami 'low' ... 'high'-1)
	Pouzije algoritmus quick sort, styl Lomuto.
	Poradie usporiadania je od najvacsieho prvku po najmensi.

	PARAMETRE:
		[in] 'data' - pole, ktoreho cast funkcia usporiada
		[in] 'low'  - index prveho prvkou casti pola, ktoru funkcia usporiada
		[in] 'high' - index za posledny prvok casti pola, ktoru funkcia usporiada

	VSTUPNA PODMIENKA:
		ak 'low' < 'high', tak 'data' ukazuje na platne pole

	PRIKLAD:
		data: {1, 2, 3, 4, 5, 6, 7, 8, 9}, low: 2, high: 7 -> data: {1, 2, 7, 6, 5, 4, 3, 8, 9}
*/
void quickSort(int* data, const size_t low, const size_t high)
{
	if (low < high - 1) {
		int pivot_index = getPivotIndex(data, low, high);
		pivot_index = partition(data, pivot_index, low, high);
		quickSort(data, low, pivot_index);
		quickSort(data, pivot_index + 1, high);
	}
	// TODO
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury
void swaper(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void vypis(int* data, int len) {
	for (int i = 0; i < len; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

void vypis(Weight* data, int a) {
	for (int i = 0; i < a; i++) {
		cout << data[i].packing << " " << data[i].product;
		cout << endl;
	}
	cout << endl;
}

void quickSort(int* data, const int n) {
	quickSort(data, 0, n);
}

int main() {




	return 0;
}
