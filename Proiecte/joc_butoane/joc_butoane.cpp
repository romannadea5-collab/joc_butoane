#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

const string RESET = "\033[0m";
const string ALB = "\033[97m";
const string ROZ = "\033[95m";
const string VERDE = "\033[92m";
const string GALBEN = "\033[93m";
const string ROSU = "\033[91m";
const string FUNDAL_ROZ = "\033[45m";
const string STRALUCIRE = "\033[1m";

void clearScreen() {
    cout << "\033[2J\033[H";
}

void printButton(string text) {
    int width = text.size() + 6;
    cout << ROZ << "+";
    for(int i = 0; i < width; i++) cout << "-";
    cout << "+\n";
    cout << "|" << FUNDAL_ROZ << ALB << "   " << text << "   " << RESET << ROZ << "|\n";
    cout << "+";
    for(int i = 0; i < width; i++) cout << "-";
    cout << "+\n" << RESET;
}

void showMenu() {
    clearScreen();
    cout << ROZ << STRALUCIRE;
    cout << "==============================\n";
    cout << "       JOCUL MEU FUN          \n";
    cout << "==============================\n\n" << RESET;

    printButton("PLAY");
    printButton("MENU");
    printButton("EXIT");

    cout << "\nApasa tasta corespunzatoare: P = PLAY, M = MENU, Q = EXIT\n";
}

void playGame() {
    clearScreen();
    cout << ROZ << STRALUCIRE << "\n--- GHICESTE NUMARUL ---\n" << RESET;

    int secret = rand() % 1000 + 1;
    int guess = 0;
    int incercari = 0;

    cout << "Am ales un numar intre 1 si 1000.\n";
    cout << "Incearca sa-l ghicesti!\n";

    while(true) {
        cout << "\nIntrodu numarul tau (0 pentru a iesi): ";
        cin >> guess;

        if(guess == 0) break;
        incercari++;
        int diff = abs(secret - guess);

        if(guess == secret) {
            cout << VERDE << "\nBravo! Ai ghicit numarul " << secret 
                 << " in " << incercari << " incercari.\n" << RESET;
            break;
        } else if(diff <= 5) {
            cout << GALBEN << "Foarte aproape! Mai incearca.\n" << RESET;
        } else if(guess < secret) {
            cout << ROSU << "Prea mic! Incearca din nou.\n" << RESET;
        } else {
            cout << ROSU << "Prea mare! Incearca din nou.\n" << RESET;
        }
    }

    cout << "\nApasa ENTER pentru a reveni la meniu...";
    cin.ignore();
    cin.get();
}

int main() {
    srand(time(NULL));
    char cmd;

    while(true) {
        showMenu();
        cin >> cmd;

        if(cmd == 'Q' || cmd == 'q') {
            cout << "\nLa revedere!\n";
            break;
        } else if(cmd == 'P' || cmd == 'p') {
            playGame();
        } else if(cmd == 'M' || cmd == 'm') {
            clearScreen();
            cout << ROZ << STRALUCIRE << "\n--- MENIU SETARI ---\n" << RESET;
            cout << "Aici pot fi setarile jocului.\n";
            cout << "Apasa ENTER pentru a reveni la meniu...";
            cin.ignore();
            cin.get();
        } else {
            cout << "\nTasta invalida. Incearca din nou.\n";
            this_thread::sleep_for(chrono::milliseconds(800));
        }
    }
}
