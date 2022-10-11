#include <iostream> // cout, cin
#include <stdlib.h> // srand, rand, atoi
#include <time.h>   // time
#include <cstring>  // c_str

bool IsDigit(char c) {
    return (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9');
}

bool IsNumber(std::string s) {
    for (char c : s) {
        if (!IsDigit(c)) {
            return false;
        }
    }
    if (s[0] != '0') {
        return true;
    }
    return false;
}

int main(int argc, char* argv[]) {
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    srand (time(NULL));

    cout << "Enter a number of dice to roll: ";
    string in = "";
    cin >> in;

    while (!IsNumber(in)) {
        cout << "Enter a NUMBER of dice to roll: ";
        cin >> in;
    }

    unsigned long long num = atoi(in.c_str());

    cout << "Enter the number of dice sides: ";
    cin >> in;

    while (!IsNumber(in)) {
        cout << "Enter the NUMBER of dice sides: ";
        cin >> in;
    }

    unsigned long long sides = atoi(in.c_str());

    unsigned long long sum = 0;
    for (unsigned long long i = num; i--;) {
        int r = rand() % sides + 1;
        sum += r;
        cout << r << " ";
    }

    unsigned long long mean = sum / num;

    cout << endl;
    cout << "The sum total of dice rolled was: " << sum << endl;
    cout << "The mean of the dice rolled was: " << mean << endl;

    return EXIT_SUCCESS;
}
