#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string normalize(string text) {
    string result = "";
    for (char c : text) {
        if (isalnum(c)) result += tolower(c);
    }
    return result;
}

int main() {
    string text = "Hola Mundo";
    string clean = normalize(text);

    int n = ceil(sqrt(clean.size()));
    vector<string> grid(n);

    for (int i = 0; i < clean.size(); i++) {
        grid[i / n] += clean[i];
    }

    string result = "";
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n; row++) {
            if (col < grid[row].size())
                result += grid[row][col];
        }
        result += ' ';
    }

    cout << "Resultado: " << result << endl;

    return 0;
}