#include<iostream>
#include<ctime>
#include <vector>

using namespace std;

class Minesweeper {

private:
    int brojRedova;
    int brojStupaca;
    int brojMina;
    vector<vector<char>> ploca;
    vector<vector<bool>> otkrivenaMista;
    vector<vector<bool>> postavljeneMine;

public:

    void postaviMine() {
        srand(time(0));

        int postavljene = 0;
        while (postavljene < brojMina) {
            int row = rand() % brojRedova;
            int col = rand() % brojStupaca;

            if (!postavljeneMine[row][col]) {
                postavljeneMine[row][col] = true;
                postavljene++;
            }
        }
    }

    Minesweeper(int row = 10, int cols = 10, int mines = 10) : brojRedova(row), brojStupaca(cols), brojMina(mines),
        ploca(brojRedova, vector<char>(brojStupaca, '-')),
        otkrivenaMista(brojRedova, vector<bool>(brojStupaca, false)),
        postavljeneMine(brojRedova, vector<bool>(brojStupaca, false))
    {
        postaviMine();
    }

    void ispisiPlocu(bool otkrijMine = false) {
        cout << "  ";
        for (int i{}; i < brojStupaca; i++) {
            cout << i << " ";
        }
        cout << endl;

        for (int i{}; i < brojRedova; i++) {
            cout << i << " ";

            for (int j{}; j < brojStupaca; j++) {
                if (otkrijMine && postavljeneMine[i][j]) {
                    cout << "* ";
                }
                else if (otkrivenaMista[i][j]) {
                    cout << ploca[i][j] << " ";
                }
                else {
                    cout << "- ";
                }
            }

            cout << endl;
        }
    }

    bool provjera(const int row, const int col) const {
        return row >= 0 && row < brojRedova && col >= 0 && col < brojStupaca;
    }

    int prebrojiMine(const int& row, const int& col) {
        int brojac{};

        for (int i{ -1 }; i <= 1; i++) {
            for (int j{ -1 }; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (provjera(row + i, col + j) && postavljeneMine[row + i][col + j]) {
                    brojac++;
                }
            }
        }

        return brojac;
    }

    void otkrijPolja(const int& row, const int& col) {
        if (!provjera(row, col) || otkrivenaMista[row][col]) {
            return;
        }

        otkrivenaMista[row][col] = true;

        int brojMina = prebrojiMine(row, col);

        if (postavljeneMine[row][col]) {
            ploca[row][col] = '*';
        }
        else if (brojMina > 0) {
            ploca[row][col] = '0' + brojMina;
        }
        else {
            ploca[row][col] = ' ';
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i != 0 || j != 0) {
                        otkrijPolja(row + i, col + j);
                    }
                }
            }
        }
    }

    void play() {
        cout << "Welcome to Minesweeper!" << endl << endl;

        while (true) {
            ispisiPlocu();
            cout << "Unesi poziciju koju zelis odigrati! red, stupac (0-" << brojRedova - 1 << ", 0-" << brojStupaca - 1 << "): ";
            int row{}, col{};
            cin >> row >> col;

            if (!provjera(row, col)) {
                cout << "Neispravan unos! Pokusaj ponovno." << endl;
                continue;
            }

            if (otkrivenaMista[row][col]) {
                cout << "Polje je vec otkriveno! Pokusaj ponovno." << endl;
                continue;
            }

            if (postavljeneMine[row][col]) {
                cout << "BOOM!!!!!! Izgubio si!" << endl;
                ispisiPlocu(true);
                break;
            }

            otkrijPolja(row, col);

            bool pobjeda = true;
            for (int i = 0; i < brojRedova; i++) {
                for (int j = 0; j < brojStupaca; j++) {
                    if (!postavljeneMine[i][j] && !otkrivenaMista[i][j]) {
                        pobjeda = false;
                        break;
                    }
                }
                if (!pobjeda) break;
            }

            if (pobjeda) {
                cout << "Cestitamo! Otkrio si sva sigurna polja!" << endl;
                ispisiPlocu(true);
                break;
            }
        }
    }
};

int main() {
    Minesweeper igra;
    igra.play();

    return 0;
}
