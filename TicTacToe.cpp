#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {

private:
    vector<vector<char>> polje;
    char trenutniIgrac;
    int brojac;

public:
    TicTacToe() : polje(3, vector<char>(3, ' ')), trenutniIgrac('X'), brojac(0) {}

    void play() {
        cout << "\nTicTacToe, dobrodosao u igru!" << endl;

        while (true) {
            bool pobjeda = false;

            igraj();
            if (brojac > 4) {
                pobjeda = provjeriPobjedu();
            }

            if (pobjeda) {
                break;
            }

            if (brojac == 9) {
                cout << "\nIzjednaceno je, nitko nije pobijedio!" << endl;
                break;
            }

            trenutniIgrac = (trenutniIgrac == 'X') ? 'O' : 'X';
        }
    }

    void ispisi_polje() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << polje.at(i).at(j);

                if (j < 2) {
                    cout << " | ";
                }
            }

            cout << endl;
            if (i < 2) cout << "--|---|--" << endl;
        }
    }

    void igraj() {
        while (true) {
            ispisi_polje();
            cout << "\nTrenutni igrac je: " << trenutniIgrac << endl;
            cout << "Odaberi poziciju (1-9): ";

            int pozicija{};
            cin >> pozicija;

            int red = (pozicija - 1) / 3;
            int stupac = (pozicija - 1) % 3;

            if ((pozicija > 0 && pozicija < 10) && polje.at(red).at(stupac) == ' ') {
                polje.at(red).at(stupac) = trenutniIgrac;
                brojac++;
                break;
            }

            else {
                cout << "\nPogresan unos, pokusaj ponovno!" << endl << endl;
            }
        }
    }

    bool provjeriPobjedu() {
        if ((polje.at(0).at(0) == trenutniIgrac && polje.at(1).at(1) == trenutniIgrac && polje.at(2).at(2) == trenutniIgrac)) {
            ispisi_polje();
            cout << "\nIgrac: " << trenutniIgrac << ", je pobijedio!" << endl;
            return true;
        }

        if ((polje.at(2).at(0) == trenutniIgrac && polje.at(1).at(1) == trenutniIgrac && polje.at(0).at(2) == trenutniIgrac)) {
            ispisi_polje();
            cout << "\nIgrac: " << trenutniIgrac << ", je pobijedio!" << endl;
            return true;
        }

        for (int i = 0; i < 3; i++) {

            if (polje.at(i).at(0) == trenutniIgrac && polje.at(i).at(1) == trenutniIgrac && polje.at(i).at(2) == trenutniIgrac) {
                ispisi_polje();
                cout << "\nIgrac: " << trenutniIgrac << ", je pobijedio!" << endl;
                return true;
            }

            if (polje.at(0).at(i) == trenutniIgrac && polje.at(1).at(i) == trenutniIgrac && polje.at(2).at(i) == trenutniIgrac) {
                ispisi_polje();
                cout << "\nIgrac: " << trenutniIgrac << ", je pobijedio!" << endl;
                return true;
            }
        }

        return false;
    }
};

int main() {
    TicTacToe main;
    main.play();
    return 0;
}
