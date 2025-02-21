#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {

private:
    string ime;
    string prezime;
    int id;
    double saldo;

public:

    Student(string a, string b, int c, double d) : ime(a), prezime(b), id(c), saldo(d) {}

    void prikaziPodatke() {

        cout << "\nIme studenta: " << ime << endl;
        cout << "Prezime studenta: " << prezime << endl;
        cout << "ID studenta: " << id << endl;
        cout << "Saldo studenta: " << saldo << endl;
    }

    void uplati(double iznos) {
        saldo += iznos;
        cout << "\nIznos je uspjesno uplacen!" << endl;
    }

    void isplati(double iznos) {
        if (iznos <= saldo) {
            saldo -= iznos;
            cout << "\nIznos je uspjesno isplacen!" << endl;
        }
        else {
            cout << "\nNema dovoljno sredstava na racunu za isplatu!" << endl;
        }
    }

    int getID() const {
        return id;
    }
};

class Sustav {

private:
    vector <Student> studenti;

public:

    void dodajStudenta(string ime, string prezime, int id, double saldo) {

        for (auto& a : studenti) {
            if (id == a.getID()) {
                cout << "\nStudent s navedenim ID-om vec postoji!" << endl;
                return;
            }
        }

        Student s(ime, prezime, id, saldo);
        studenti.push_back(s);
    }

    void uplatiNovac(int id, double iznos) {

        for (auto& a : studenti) {
            if (id == a.getID()) {
                a.uplati(iznos);
                return;
            }
        }

        cout << "\nStudent s navedenim ID-om nije pronaden!" << endl;
    }

    void isplatiNovac(int id, double iznos) {
        for (auto& a : studenti) {
            if (id == a.getID()) {
                a.isplati(iznos);
                return;
            }
        }

        cout << "\nStudent s navedenim ID-om nije pronaden!" << endl;
    }

    void prikaziSveStudente() {

        if (studenti.size() == 0) {
            cout << "\nLista je prazna!" << endl;
            return;
        }

        for (auto& a : studenti) {
            a.prikaziPodatke();
        }
    }
};

int main() {

    Sustav sustav;

    int odabir{ -1 };

    do {

        cout << "\nOdaberite opciju:" << endl;
        cout << "1. Dodaj studenta" << endl;
        cout << "2. Uplati novac" << endl;
        cout << "3. Isplati novac" << endl;
        cout << "4. Prikazi sve studente" << endl;
        cout << "0. Izlaz" << endl;
        cout << "\nOdabir: ";
        cin >> odabir;

        switch (odabir) {

        case 1: {
            string ime, prezime;
            int id;
            double saldo;

            cout << "\nUnesi ime studenta: ";
            cin >> ime;
            cout << "Unesi prezime studenta: ";
            cin >> prezime;
            cout << "Unesi ID studenta: ";
            cin >> id;
            cout << "Unesi saldo studenta: ";
            cin >> saldo;

            sustav.dodajStudenta(ime, prezime, id, saldo);
            break;
        }

        case 2: {
            int id;
            double iznos;

            cout << "\nUnesi ID studenta: ";
            cin >> id;
            cout << "Unesi iznos za uplatu: ";
            cin >> iznos;

            sustav.uplatiNovac(id, iznos);
            break;
        }

        case 3: {
            int id;
            double iznos;

            cout << "\nUnesi ID studenta: ";
            cin >> id;
            cout << "Unesi iznos za isplatu: ";
            cin >> iznos;

            sustav.isplatiNovac(id, iznos);
            break;
        }

        case 4:
            sustav.prikaziSveStudente();
            break;

        case 0:
            cout << "\nIzlaz!" << endl;
            break;

        default:
            cout << "\nKriv unos, pokusaj ponovno!" << endl;
        }

    } while (odabir != 0);

    return 0;
}
