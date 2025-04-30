#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

// Converts hex digit to 4-bit binary string
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

bool isValidHex(const string& hexstr) {
    for (char c : hexstr) {
        if (!isxdigit(c)) return false;
    }
    return true;
}

void enterLabels(vector<string>& labels) {
    labels.clear();
    cout << "Enter 16 category labels (space-separated):\n";
    for (int i = 0; i < 16; ++i) {
        string label;
        cin >> label;
        labels.push_back(label);
    }
    cout << "Labels set successfully.\n";
}

void decodeHex(const string& hexInput, const vector<string>& labels, map<string, int>& labelCounter) {
    int labelIndex = 0;
    cout << "\nHex: " << hexInput << endl;
    cout << "Binary with label mappings (for '1' bits):\n";

    for (char hexDigit : hexInput) {
        string binary = hexDigitToBinary(hexDigit);
        for (char bit : binary) {
            cout << bit;
            if (bit == '1') {
                cout << " ---> " << labels[labelIndex];
                labelCounter[labels[labelIndex]]++;
            }
            cout << endl;
            labelIndex = (labelIndex + 1) % 16;
        }
    }
}

void showSummary(const map<string, int>& labelCounter) {
    cout << "\n==== Label Summary ====" << endl;
    for (const auto& pair : labelCounter) {
        cout << setw(10) << pair.first << " : " << pair.second << " times\n";
    }
}

void saveToFile(const string& hexInput, const vector<string>& labels, const map<string, int>& labelCounter) {
    ofstream outFile("hex_decode_output.txt");
    if (!outFile) {
        cerr << "Error writing to file." << endl;
        return;
    }
    int labelIndex = 0;
    outFile << "Hex: " << hexInput << "\n";
    outFile << "Binary with label mappings:\n";

    for (char hexDigit : hexInput) {
        string binary = hexDigitToBinary(hexDigit);
        for (char bit : binary) {
            outFile << bit;
            if (bit == '1') {
                outFile << " ---> " << labels[labelIndex];
            }
            outFile << endl;
            labelIndex = (labelIndex + 1) % 16;
        }
    }

    outFile << "\n==== Label Summary ====" << endl;
    for (const auto& pair : labelCounter) {
        outFile << pair.first << ": " << pair.second << " times\n";
    }

    outFile.close();
    cout << "\nOutput saved to 'hex_decode_output.txt'.\n";
}

int main() {
    vector<string> labels(16);
    map<string, int> labelCounter;
    string hexInput;

    int choice;
    do {
        cout << "\n===== Hex Decoder Menu =====\n";
        cout << "1. Enter Custom Labels\n";
        cout << "2. Enter Hex Value\n";
        cout << "3. Show Summary\n";
        cout << "4. Export to File\n";
        cout << "5. Quit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enterLabels(labels);
                break;
            case 2:
                cout << "Enter a hexadecimal string: ";
                cin >> hexInput;
                if (!isValidHex(hexInput)) {
                    cout << "Invalid hex input.\n";
                    break;
                }
                labelCounter.clear();
                decodeHex(hexInput, labels, labelCounter);
                break;
            case 3:
                showSummary(labelCounter);
                break;
            case 4:
                saveToFile(hexInput, labels, labelCounter);
                break;
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
