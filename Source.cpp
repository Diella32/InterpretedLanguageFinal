#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

// Function to interpret SimpleStack programs
void interpret(ifstream& file) {
    stack<string> stack;
    string line;

    while (getline(file, line)) {
        if (line.find("PUSH") == 0) {
            string arg = line.substr(5);
            stack.push(arg);
        }
        else if (line == "PRINT") {
            if (stack.empty()) {
                cerr << "Error: PRINT requires a value on the stack." << endl;
                 return;
            }
           
            cout << stack.top() << endl;
            stack.pop();
        }
        else if (line == "READ") {
            string input;
            cout << "Enter a string: ";
            getline(cin, input);
            stack.push(input);
        }
        else if (line == "MULTIPLY") {
            if (stack.size() < 2) {
                cerr << "Error: MULTIPLY requires at least two values on the stack." << endl;
                return;
            }
            int b = stoi(stack.top()); stack.pop();
            int a = stoi(stack.top()); stack.pop();
            stack.push(to_string(a * b));
        }
        else if (line == "NUMBER") {
            string input;
            cout << "Enter a number: ";
            getline(cin, input);
            stack.push(input);
        }
        else if (line == "REVERSE") {
            if (stack.empty()) {
                cerr << "Error: REVERSE requires a value on the stack." << endl;
                return;
            }
            string str = stack.top();
            stack.pop();
            reverse(str.begin(), str.end());
            stack.push(str);
           // cout << str << endl;
        }
        else if (line == "numberOfTimesToRepeat") {
            string numInput;
            cout << "Enter the number of times to repeat: ";
            cin >> numInput;
            stack.push(numInput);
         }
        else if (line == "charInput") {
            string charInput;
            cout << "Enter a character to repeat: ";
            cin >> charInput;
            stack.push(charInput);
        }
        else if (line == "REPEAT") {
            if (stack.size() < 2) {
                cerr << "Error: REPEAT requires both character and count on the stack." << endl;
                return;
            }
            int count = stoi(stack.top()); stack.pop();
            string character = stack.top(); stack.pop();
            for (int i = 0; i < count; ++i) {
                cout << character;
            }
            cout << endl;
            }
        else if (line == "EXIT") {
            return; // Exit program
        }
        else {
            cerr << "Error: Invalid instruction." << endl;
            return;
        }
    }
}

int main() {
    ifstream file("hello.txt"); 
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }
    interpret(file);
    file.close();
    return 0;
}


