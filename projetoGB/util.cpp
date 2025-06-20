#include <string>
#include <iostream>

using namespace std;

string removeSpaces(string input) {
    string result;
    for (char c : input) {
        if (!isspace(c)) {
            result += c;
        }
    }
    return result;
}
void cleanTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void tapToContinue() {
    string str;
    cout << "\nPressione ENTER para prosseguir...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa entrada pendente
    getline(cin, str);
}