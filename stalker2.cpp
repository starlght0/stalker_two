#include <iostream>
#include <thread>
using namespace std;

void drawmap(int x, int y, char player, char win, int winx, int winy);
void walk(int &x, int &y);
void wall();

int main()
{
    setlocale(LC_ALL, "rus"); 
    int x = 5; 
    int y = 5; 
    char player = 'o'; 
    char win = 'x';
    int winx = 1;
    int winy = 2;

    while(1) {
        drawmap(x, y, player, win, winx, winy);

        cout << "your coordinate: " << "x" << x << " y" << y << "\n";
        walk(x, y);
        system("cls");
        if (x == winx && y == winy) {
            cout << "\t\t\t\t\tYou win\n\n\n\n";
        }
    }   
    return 0;
}

void drawmap(int x, int y, char player, char win, int winx, int winy) {
    for (int i = 0; i < 11; i++) { // переходы на новую строку
        for (int j = 0; j < 11; j++) { // проверки выводить ли клад и игрока, если нет то заполняет поле *
            if (i == winx && j == winy) { 
                if (i == x && j == y) { 
                    cout << player << " ";
                }
                else {
                    cout << win << " ";
                }
            }
            else if (i == x && j == y) {
                cout << player, cout << " ";
            }
            else {
                cout << "* ";
            }
        }
            cout << "\n"; // когда j становится больше 10 то срабатывает переход на новую строку
    }
}

void walk(int &x, int &y) {
    char input;
    cin >> input;

    if (input == 'w' && x > 0) {
        x--;
    }
    else if (input == 'a' && y > 0) {
        y--;
    }
    else if (input == 's' && x < 10) {
        x++;
    }
    else if (input == 'd' && y < 10) {
        y++;
    }
    else if (input == 'q') {
        exit(0);
    }
}

void wall() {

}
