#include <iostream> // cout, cin
#include <stdlib.h> // srand, rand, atoi
#include <time.h>   // time
#include <cstring>  // c_str

bool IsDigit(char c) {
    return int(c) >= 48 && int(c) <= 57;
}

bool IsNumber(std::string s) {
    for (const char &c : s) {
        if (!IsDigit(c)) {
            return false;
        }
    }
    return s[0] != '0';
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
