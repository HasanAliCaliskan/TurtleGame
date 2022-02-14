#include <iostream>
#include <ctime>
#define SIZE 8
using namespace std;

class TurtleGame 
{
public:
	void setTurtle(int x, int y) {
		turtle_x = x;
		turtle_y = y;
	}
	void setFood(int x, int y) {
		food_x = x;
		food_y = y;
	}
	void setPoint(int p) {
		point = p;
	}

	int getTurtle_x() {
		return turtle_x;
	}
	int getTurtle_y() {
		return turtle_y;
	}
	int getFood_x() {
		return food_x;
	}
	int getFood_y() {
		return food_y;
	}
	int getPoint() {
		return point;
	}
	
	int coordinateControl() {
		if (getTurtle_x() == getFood_x() && getTurtle_y() == getFood_y()) {
			return 1; // koordinatlar eþit
		}
		else {
			return 0; // koordinatlar eþit deðil
		}
	}

private:
	int turtle_x;
	int turtle_y;
	int food_x;
	int food_y;
	int point;
};

void createTurtle(string dizi1[][SIZE], TurtleGame* geym);
void createFood(string dizi2[][SIZE], TurtleGame* geeeym);
void gameScreen(string dizi3[][SIZE]);
void anaEkran(string dizi[][SIZE], TurtleGame game);
int moveTurtle(string dizi[][SIZE], TurtleGame* gaame);

int main()
{
	string field[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			field[i][j] = "*";
		}
	}

	TurtleGame a{};
	anaEkran(field, a);

	return 0;
}

void anaEkran(string dizi[][SIZE], TurtleGame game) {
	cout << "\n\n\t\t**********  TURTLE  GAME  **********\n\n *** T -> Turtle\n *** F -> Food" << endl;
	
	game.setPoint(0);
	createTurtle(dizi, &game);
	createFood(dizi, &game);
	gameScreen(dizi);
	while (1) {
		if (moveTurtle(dizi, &game) == 1) {
			createFood(dizi, &game);
		}
		gameScreen(dizi);
	}
}

void createTurtle(string dizi1[][SIZE], TurtleGame* geym) {
	srand(time(0));
	int random_x = rand() % 8;
	int random_y = rand() % 8;
	geym->setTurtle(random_x, random_y);
	dizi1[random_x][random_y] = { "T" };
}

void createFood(string dizi2[][SIZE], TurtleGame* geeeym) {
	srand(time(0)*13);
	int random_x = rand() % 8;
	int random_y = rand() % 8;
	geeeym->setFood(random_x, random_y);

	if (geeeym->coordinateControl() == 1) { // koordinatlar eþit
		cout << " *** POINT : " << geeeym->getPoint() + 10 << endl;
		geeeym->setTurtle(random_x, random_y); // turtle burada artýk
		dizi2[random_x][random_y] = { "T" };
	}
	else {  // koordinatlar eþit deðil
		geeeym->setFood(random_x, random_y); // foodu yerleþtir
		dizi2[random_x][random_y] = { "F" };
	}
}

int moveTurtle(string dizi4[][SIZE], TurtleGame* gaame) {
	string cevap;
	cout << "\n  Yukari  --> 'y'\n";
	cout << "  Asagi  --> 'a'\n";
	cout << "  Saga  --> 'sa'\n";
	cout << "  Sola  --> 'so' ...  "; cin >> cevap; cout << endl;
	
	if (cevap == "y") {
		if (gaame->getTurtle_x() - 1 >= 0) {
			gaame->setTurtle(gaame->getTurtle_x() - 1, gaame->getTurtle_y());
			if (gaame->coordinateControl() == 1) {
				dizi4[gaame->getTurtle_x()][gaame->getTurtle_y()] = { "T" };
				dizi4[gaame->getTurtle_x() + 1][gaame->getTurtle_y()] = { "*" };
				return 1;
			}
			dizi4[gaame->getTurtle_x()][gaame->getTurtle_y()] = { "T" };
			dizi4[gaame->getTurtle_x() + 1][gaame->getTurtle_y()] = { "*" };
		}
		else {
			cout << "*** Turtle alanin disina cikamaz!" << endl;
		}
	}
	else if (cevap == "a") {
		if (gaame->getTurtle_x() + 1 < 8) {
			gaame->setTurtle(gaame->getTurtle_x() + 1, gaame->getTurtle_y());
			if (gaame->coordinateControl() == 1) {
				dizi4[gaame->getTurtle_x()][gaame->getTurtle_y()] = { "T" };
				dizi4[gaame->getTurtle_x() - 1][gaame->getTurtle_y()] = { "*" };
				return 1;
			}
			dizi4[gaame->getTurtle_x()][gaame->getTurtle_y()] = { "T" };
			dizi4[gaame->getTurtle_x() - 1][gaame->getTurtle_y()] = { "*" };
		}
		else {
			cout << "*** Turtle alanin disina cikamaz!" << endl;
		}
	}
	else if (cevap == "sa") {
		if (gaame->getTurtle_y() + 1 < 8) {
			gaame->setTurtle(gaame->getTurtle_x(), gaame->getTurtle_y() + 1);
			if (gaame->coordinateControl() == 1) {
				dizi4[gaame->getTurtle_x()][gaame->getTurtle_y()] = { "T" };
				dizi4[gaame->getTurtle_x()][gaame->getTurtle_y() - 1] = { "*" };
				return 1;
			}
			dizi4[gaame->getTurtle_x()][gaame->getTurtle_y()] = { "T" };
			dizi4[gaame->getTurtle_x()][gaame->getTurtle_y() - 1] = { "*" };
		}
		else {
			cout << "*** Turtle alanin disina cikamaz!" << endl;
		}
	}
	else if (cevap == "so") {
		if (gaame->getTurtle_y() - 1 >= 0) {
			gaame->setTurtle(gaame->getTurtle_x(), gaame->getTurtle_y() - 1);
			if (gaame->coordinateControl() == 1) {
				dizi4[gaame->getTurtle_x()][gaame->getTurtle_y()] = { "T" };
				dizi4[gaame->getTurtle_x()][gaame->getTurtle_y() + 1] = { "*" };
				return 1;
			}
			dizi4[gaame->getTurtle_x()][gaame->getTurtle_y()] = { "T" };
			dizi4[gaame->getTurtle_x()][gaame->getTurtle_y() + 1] = { "*" };
		}
		else {
			cout << "*** Turtle alanin disina cikamaz!" << endl;
		}
	}
	else {
		cout << " Hata! Yalnizca yukaridakiler yazilabilir." << endl;
	}
}

void gameScreen(string dizi3[][SIZE]) {
	cout << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << "   " << dizi3[i][j];
		}
		cout << endl << endl;
	}
}