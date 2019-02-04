//
//  main.cpp
//  RomanNumbers
//  A decimal to roman and roman to decimal converter.
//
//  Created by Martín Figueroa Padilla on 2/3/19.
//  Copyright © 2019 Martín Figueroa Padilla. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

string dec2rom(int num) {
    if (num > 0 && num < 4000) {
        int n = num;
        string _romans[3][10] = {
            { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
            { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
            { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }
        };
        
        int thousands = floor(n / 1000);
        n -= thousands * 1000;
        int hundreds = floor(n / 100);
        n -= hundreds * 100;
        int tens = floor(n / 10);
        n -= tens * 10;
        int units = n;
        
        return string(thousands, 'M') + _romans[0][hundreds]
            + _romans[1][tens] + _romans[2][units];
        
    }
    
    return "NUMBER_OUT_OF_RANGE";
}

int rom2dec(string rom) {
    string needles[6] = { "IV", "IX", "XL", "XC", "CD", "CM" };
    int needlesv[6] = { 4, 9, 40, 90, 400, 900 };
    int number = 0;
    
    string r = rom;
    for (int i = 0; i < 6; i++) {
        long temp = r.find(needles[i]);
        if (temp >= 0) {
            r = r.replace(temp, needles[i].length(), "");
            number += needlesv[i];
        }
    }
    
    for (int i = 0; i < r.length(); i++) {
        switch (r[i]) {
            case 'I': number += 1; break;
            case 'V': number += 5; break;
            case 'X': number += 10; break;
            case 'L': number += 50; break;
            case 'C': number += 100; break;
            case 'D': number += 500; break;
            case 'M': number += 1000; break;
        }
    }
    
    return number;
}

int modeSelect(void) {
    cout << "Select an option to continue:\n";
    cout << "1. Convert decimal to roman\n";
    cout << "2. Convert roman to decimal\n";
    cout << "3. Exit program\n";
    cout << "Option > ";
    int selection = -1;
    cin >> selection;
    cout << "\n";
    return selection;
}

void wait2continue() {
    cout << "Press any key to continue...";
    getchar();
    getchar();
    cout << "\n";
}

void convert2roman(void) {
    int input = 0;
    cout << "Input decimal number: ";
    cin >> input;
    cout << "Convertion to roman: " + dec2rom(input) + "\n";
    wait2continue();
}

void convert2decimal(void) {
    string input = "";
    cout << "Input roman number: ";
    cin >> input;
    cout << "Convertion to decimal: " + to_string(rom2dec(input)) + "\n";
    wait2continue();
}

int main(int argc, const char * argv[]) {
    cout << "Hello!\nWelcome to the decimal and roman converter.\n\n";
    int run = 1;
    while (run == 1) {
        switch (modeSelect()) {
            case 1: convert2roman(); break;
            case 2: convert2decimal(); break;
            case 3: run = 0; break;
            default: cout << "This option is not valid.\n";
        }
    }
    
    cout << "Goodbye!\n";
    return 1;
}
