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

void showMainMenu() {
    cout << "\n\n";
    printButton("Guess Game - Apasa S pentru START");
    cout << "\n";
    printButton("Nivel: E=Usor M=Mediu H=Greu");
    cout << "\n";
    printButton("Q = Iesire");
    cout << "\nAlege optiunea: ";
}

int levelToLimit(char c) {
    if (c=='E'||c=='e') return 10;
    if (c=='M'||c=='m') return 50;
    return 100;
}

int main() {
    srand((unsigned)time(nullptr));

    char cmd, nivel='H';
    int limita = 100;

    while (true) {
        showMainMenu();
        string in;
        getline(cin, in);
        if (in.size()==0) continue;
        cmd = in[0];

        if (cmd=='Q'||cmd=='q') {
            cout << "La revedere!\n";
            break;
        }

        if (cmd=='E'||cmd=='e'||cmd=='M'||cmd=='m'||cmd=='H'||cmd=='h') {
            nivel = cmd;
            limita = levelToLimit(nivel);
            cout << "Nivel schimbat.\n";
            continue;
        }

        if (cmd=='S'||cmd=='s') {
            int secret = rand()%limita + 1;
            int guess = -1;
            cout << "\n--- GHICESTE NUMARUL (1-" << limita << ") ---\n";

            while (true) {
                cout << "Numar (0=renunt): ";
                getline(cin, in);
                if (in.size()==0) continue;

                bool ok=true;
                for (char c : in)
                    if (c<'0'||c>'9') ok=false;

                if (!ok) { cout<<"Scrie doar cifre.\n"; continue; }

                guess = stoi(in);
                if (guess==0) { cout<<"Renuntat.\n"; break; }
                if (guess>secret) cout<<"Prea mare!\n";
                else if (guess<secret) cout<<"Prea mic!\n";
                else { cout<<"Bravo! Ai ghicit!\n"; break; }
            }

            cout << "Repetam? (Y/N): ";
            getline(cin, in);
            if (in.size()>0&&(in[0]=='Y'||in[0]=='y')) continue;
        }
    }
    return 0;
}
