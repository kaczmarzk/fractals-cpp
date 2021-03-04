#include <cstdio>
#include <iostream>
#include "sierpinski_carpet.h"
#include "koch_snowflake.h"

using namespace std;

int main() {
	printf(R"(

##########################################################
 _                                                  _
| | ____ _  ___ _____ __ ___   __ _ _ __ ______   _| | __
| |/ / _` |/ __|_  / '_ ` _ \ / _` | '__|_  /\ \ / / |/ /
|   < (_| | (__ / /| | | | | | (_| | |   / /  \ V /|   <
|_|\_\__,_|\___/___|_| |_| |_|\__,_|_|  /___|  \_/ |_|\_\

##########################################################

Autor: Adam Kaczmarzyk

Witaj w programie generujacym Platek Kocha oraz Dywan Sierpinskiego.
Wybierz ktory z podanych powyzej chcesz wygenerowac.
Podaj rowniez liczbe naturalna n, gdzie n < 6, ktora definiuje liczbe krokow.

)");

	char input;

	do {
		
		char type;
		int n;

		printf("\nKtory fraktal chcesz wygenerowac?");
		printf("\nS - Dywan Sierpinskiego | K - Platek Kocha :: ");
		while (!(cin >> type) || !(tolower(type) == 107 || tolower(type) == 115)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		printf("\nPodaj liczbe krokow (n < 6): ");
		while (!(cin >> n) || n < 0 || n > 5) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (tolower(type))
		{
		case 107: buildKochSnowflake(n);
		break;
		case 115: buildSierpinskiCarpet(n);
			break;
		}
	
		printf("\n\nChcesz powtorzyc dzialanie programu? y/N : ");
		scanf_s(" %c", &input);
	
	} while(input == 'y');

	return 0;
}