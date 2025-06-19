#include <string>

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