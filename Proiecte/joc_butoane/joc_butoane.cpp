#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

const string RESET = "\033[0m";
const string ALB = "\033[97m";
const string ROZ = "\033[95m";
const string FUNDAL_ROZ = "\033[45m";
const string FUNDAL_ALB = "\033[107m";
const string FUNDAL_GALBEN = "\033[103m";
const string STRALUCIRE = "\033[1m";

void clearScreen() {
    cout << "\033[2J\033[H";
}

void starAnimation(int frames=8) {
    vector<string> stars = {
        "        *       .       *        .        *     ",
        "   .        *         .      *        .        *",
        " *     .        *        .       *      .      ",
        "      .    *        .       *        .     *   "
    };

    for(int i=0;i<frames;i++){
        clearScreen();
        cout << STRALUCIRE << ROZ << "\n\n" << stars[i % stars.size()] << "\n\n" << RESET;
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

void printButton(string text) {
    int width = text.size() + 4; 
    cout << ROZ << "+";
    for(int i=0;i<width;i++) cout << "-";
    cout << "+\n";

    cout << "|" << FUNDAL_ROZ << ALB << "  " << text << "  " << RESET << ROZ << "|\n";

    cout << "+";
    for(int i=0;i<width;i++) cout << "-";
    cout << "+\n" << RESET;
}

void showTitle() {
    cout << ROZ;
    cout << "=====================================\n";
    cout << "         JOC GHICESTE NUMARUL        \n";
    cout << "=====================================\n\n" << RESET;
}

void showMenu() {
    showTitle();
    printButton("START GAME");
    printButton("IESIRE");
    cout << "Apasa 'S' pentru Start sau 'Q' pentru Iesire\n";
}

int levelToLimit(char c) {
    if(c=='E'||c=='e') return 10;
    if(c=='M'||c=='m') return 50;
    return 100;
}

void printNumberBox(int num) {
    string text = to_string(num);
    int width = 5; 
    int padding = (width - text.size())/2;

    cout << FUNDAL_ALB << ROZ << "+-----+\n";
    cout << "|";
    for(int i=0;i<padding;i++) cout << " ";
    cout << text;
    for(int i=0;i<width - padding - text.size();i++) cout << " ";
    cout << "|\n";
    cout << "+-----+" << RESET << " ";
}

void startGame(int limita) {
    starAnimation();

    cout << "\n🌙 Ghiceste numarul intre 1 si " << limita << " 🌙\n";

    int secret = rand() % limita + 1;
    int guess;

    while(true) {
        cout << "\nNumar (0 = renunt): ";
        cin >> guess;

        if(guess==0) {
            cout << "Ai renuntat.\n";
            break;
        }

        cout << "Numarul tau: ";
        printNumberBox(guess);
        cout << "\n";

        if(guess > secret) {
            cout << "Prea mare!\n";
        } else if(guess < secret) {
            cout << "Prea mic!\n";
        } else {
            cout << FUNDAL_GALBEN << ROZ << STRALUCIRE
                 << "\n💗💗 FELICITARI!!! AI GHICIT! 💗💗\n" << RESET;
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    char cmd;
    int limita = 100;

    while(true) {
        clearScreen();
        showMenu();

        cin >> cmd;

        if(cmd=='Q' || cmd=='q') {
            cout << "\nLa revedere! 💗\n";
            break;
        }

        if(cmd=='S' || cmd=='s') {
            startGame(limita);
            cout << "\nApasa ENTER pentru meniu...";
            cin.ignore();
            cin.get();
        }

        if(cmd=='E'||cmd=='e'||cmd=='M'||cmd=='m'||cmd=='H'||cmd=='h') {
            limita = levelToLimit(cmd);
            cout << "\nNivel schimbat la " << limita << "\n";
        }
    }
}
