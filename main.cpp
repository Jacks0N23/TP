#include <iostream>
#include <conio.h>
#include "Matrix.h"
#include "search.h"

using namespace std;

int main() {

    matrix a;
    bool flag;
    char  c;
    string s;

    cout << "Hello, World!" << endl;


    char in[80];
    cout << "Enter input file name " << endl;
    gets(in);
    ifstream input_file(in);

    char out[80];
    cout << "Enter output file name " << endl;
    gets(out);
    ofstream output_file(out);

   // addLog("Programm is running",a,output_file);
do {
    cout << "1) Make matrix from txt\n2)Free memory\n3)Change value\n4)Change matrix size\n5)Search\n6)Exit" << endl;
    cin >> c;
    switch (c) {
        case '1': {
            flag = input(a, input_file, output_file);
        }
        case '2': {
            FreeMem(a);
        }
        case '3': {
            if (flag) {
                ChangeElem(a, output_file);
            }
            else
                cout << "firstly input matrix" << endl;
        }
        case '4': {
            if (flag) {
                ChangeSize(a, output_file);
            }
            else
                cout << "firstly input matrix" << endl;
        }
        case '5': {
            if (flag) {
                cout << "poka ne gotovo" << endl;
            }
            else
                cout << "firstly input matrix" << endl;
        }
        case '6': {
            FreeMem(a);
            _Exit(-1);
        }
        default:
            cout << "incorrect command" << endl;
    }
} while (c!='6');
    getch();

    return 0;
}