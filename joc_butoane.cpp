#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void printButton(const string &label) {
    cout << "+";
    for (size_t i = 0; i < label.size() + 2; ++i) cout << "-";
    cout << "+\n";

    cout << "| " << label << " |\n";

    cout << "+";
    for (size_t i = 0; i < label.size() + 2; ++i) cout << "-";
    cout << "+\n";
}

void showTitle() {
    cout << "\n\n";
    cout << "=====================================\n";
    cout << "         JOC GHICESTE NUMARUL        \n";
    cout << "=====================================\n";
}

void showMainMenu() {
    showTitle();
    cout << "\n";
    printButton("S = START");
    printButton("Nivel: E = Usor, M = Mediu, H = Greu");
    printButton("Q = Iesire");
    cout << "\nAlege optiunea: ";
}

int levelToLimit(char c) {
    if (c == 'E' || c == 'e') return 10;
    if (c == 'M' || c == 'm') return 50;
    return 100; // default: Hard
}

int main() {
    srand((unsigned)time(nullptr));

    char cmd, nivel = 'H';
    int limita = 100;
    string in;

    while (true) {
        showMainMenu();
        getline(cin, in);
        if (in.size() == 0) continue;
        cmd = in[0];

        if (cmd == 'Q' || cmd == 'q') {
            cout << "\nLa revedere!\n";
            break;
        }

        if (cmd == 'E' || cmd == 'e' ||
            cmd == 'M' || cmd == 'm' ||
            cmd == 'H' || cmd == 'h') {

            nivel = cmd;
            limita = levelToLimit(nivel);
            cout << "\nNivel schimbat! Limita este acum: " << limita << "\n\n";
            continue;
        }

        if (cmd == 'S' || cmd == 's') {
            int secret = rand() % limita + 1;
            int guess = -1;

            cout << "\n-------------------------------------\n";
            cout << "         GHICESTE NUMARUL!           \n";
            cout << "              (1 - " << limita << ")             \n";
            cout << "-------------------------------------\n";

            while (true) {
                cout << "Numar (0 = renunt): ";
                getline(cin, in);

                if (in.size() == 0) continue;

                bool ok = true;
                for (char c : in)
                    if (c < '0' || c > '9') ok = false;

                if (!ok) {
                    cout << "Scrie doar cifre.\n";
                    continue;
                }

                guess = stoi(in);

                if (guess == 0) {
                    cout << "Ai renuntat.\n";
                    break;
                }

                if (guess > secret) cout << "Prea mare!\n";
                else if (guess < secret) cout << "Prea mic!\n";
                else {
                    cout << "\n=====================================\n";
                    cout << "           FELICITARI!!!             \n";
                    cout << "         AI GHICIT NUMARUL!          \n";
                    cout << "=====================================\n";
                    break;
                }
            }

            cout << "\nVrei sa joci din nou? (Y/N): ";
            getline(cin, in);
            if (in.size() > 0 && (in[0] == 'Y' || in[0] == 'y'))
                continue;
        }
    }

    return 0;
}
