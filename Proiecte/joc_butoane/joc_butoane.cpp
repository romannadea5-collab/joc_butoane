#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void setColor(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }

void typeOut(string s, int speed = 5) {
    for (char c : s) {
        cout << c << flush;
        Sleep(speed);
    }
}

void starAnimation() {
    string stars[4] = {
        "        *       .       *        .        *     ",
        "   .        *         .      *        .        *",
        " *     .        *        .       *      .      ",
        "      .    *        .       *        .     *   "
    };

    for (int i = 0; i < 6; i++) {
        setColor(13);
        cout << "\n\n" << stars[i % 4] << "\n\n";
        Sleep(150);
        system("cls");
    }
}
void pixelButton(string text) {
    setColor(13);
    cout << "############################################\n";
    cout << "#                                          #\n#  ";
    typeOut(text, 1);
    cout << "\n#                                          #\n";
    cout << "############################################\n\n";
}

void showTitle() {
    setColor(13);
    cout <<
    "#############################################################\n"
    "#                                                           #\n"
    "#               💗 JOC-GHICESTE NUMARUL 💗                 #\n"
    "#                                                           #\n"
    "#############################################################\n\n";
}

void showMenu() {
    showTitle();
    pixelButton("START GAME   (S)");
    pixelButton("NIVEL:  E = Usor | M = Mediu | H = Greu");
    pixelButton("IESIRE        (Q)");

    setColor(15);
    cout << "Alege optiunea: ";
}

int levelToLimit(char c) {
    if (c == 'E' || c == 'e') return 10;
    if (c == 'M' || c == 'm') return 50;
    return 100;
}

void startGame(int limita) {
    system("cls");
    starAnimation();  
    setColor(13);
    typeOut("\n🌙 Ghiceste numarul (1 - " + to_string(limita) + ") 🌙\n\n", 10);

    int secret = rand() % limita + 1;
    string input;

    while (true) {
        setColor(15);
        cout << "Numar (0 = renunt): ";
        getline(cin, input);

        bool valid = true;
        for (char c : input)
            if (c < '0' || c > '9') valid = false;

        if (!valid) {
            cout << "Scrie doar cifre.\n";
            continue;
        }

        int guess = stoi(input);
        if (guess == 0) {
            cout << "Ai renuntat.\n";
            break;
        }

        if (guess > secret) {
            Beep(600, 80);
            cout << "Prea mare!\n";
        }
        else if (guess < secret) {
            Beep(400, 80);
            cout << "Prea mic!\n";
        }
        else {
            Beep(900, 200);
            setColor(13);
            cout << "\n💗💗 FELICITARI!!! AI GHICIT! 💗💗\n\n";
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    char cmd;
    string input;
    int limita = 100;

    while (true) {
        system("cls");
        showMenu();

        getline(cin, input);
        if (input.size() == 0) continue;
        cmd = input[0];

        if (cmd == 'Q' || cmd == 'q') {
            typeOut("\nLa revedere! 💗\n", 10);
            break;
        }

        if (cmd == 'E' || cmd == 'e' ||
            cmd == 'M' || cmd == 'm' ||
            cmd == 'H' || cmd == 'h') {
            limita = levelToLimit(cmd);
            cout << "\nNivel schimbat la " << limita << "\n";
            Sleep(600);
            continue;
        }

        if (cmd == 'S' || cmd == 's') {
            startGame(limita);
            cout << "\nApasa ENTER pentru meniu...";
            getline(cin, input);
        }
    }

    return 0;
}
