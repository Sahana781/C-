#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isValidHex(const string& hexstr) {
    for (char c : hexstr) {
        if (!isxdigit(c)) {
            return false;
        }
    }
    return true;
}

string hexDigitToBinary(char hexDigit) {
    switch (toupper(hexDigit)) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
        default: return "????";
    }
}

int main() {
    string labelsets[6][16] = {
        {"As","Ab","CD","EF","GH","IJ","KL","MN","As","Ab","CD","EF","GH","IJ","KL","MN"},
        {"As","Ab","CD","EF","GH","IJ","KL","MN","As","Ab","CD","EF","GH","IJ","KL","MN"},
        {"As","Ab","CD","EF","GH","IJ","KL","MN","As","Ab","CD","EF","GH","IJ","KL","MN"},
        {"As","Ab","CD","EF","GH","IJ","KL","MN","As","Ab","CD","EF","GH","IJ","KL","MN"},
        {"As","Ab","CD","EF","GH","IJ","KL","MN","As","Ab","CD","EF","GH","IJ","KL","MN"},
        {"As","Ab","CD","EF","GH","IJ","KL","MN","As","Ab","CD","EF","GH","IJ","KL","MN"}
    };

    for (int iteration = 1; iteration <= 6; ++iteration) {
        cout << "\n__bit" << iteration << "-----" << endl;
        string hexInput;
        cout << "Enter a hexadecimal string (or 'Quit' to exit): ";
        cin >> hexInput;

        if (hexInput == "Quit") {
            cout << "Good Bye" << endl;
            return 0;
        }

        if (!isValidHex(hexInput)) {
            cout << "Invalid hexadecimal input." << endl;
            continue;
        }

        string* labels = labelsets[iteration - 1];
        int labelIndex = 0;
        cout << "Binary Equivalent of hexadecimal: " << hexInput << endl;

        for (char hexDigit : hexInput) {
            string binary = hexDigitToBinary(hexDigit);
            for (char bit : binary) {
                cout << bit;
                if (bit == '1') {
                    cout << " ----> " << labels[labelIndex];
                }
                cout << endl;
                labelIndex = (labelIndex + 1) % 16;
            }
        }
    }

    return 0;
}

