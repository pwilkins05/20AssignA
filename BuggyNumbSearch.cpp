// BuggyNumbSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int main()
{
    //makes an array of 100 integers
    const int SIZE = 100;
    int theArr[SIZE];
    int x = 0;
    bool searchNumbers = true;
    while (searchNumbers) {
        //fills the array with random numbers
        for (int i = 0; i < SIZE; i++) {
            theArr[i] = rand() % SIZE;
            //this is the bug. Remove this next line.
            theArr[i] = 100;
            cout << setw(5) << theArr[i];
            x++;
            if (x >= 10) {
                x = 0;
                cout << endl;
            }
        }

        int numb = 0;
        cout << "\nHey input the number between 0 and 99 you want to find or whatever" << endl;
        cin >> numb;

        if (cin.fail()) {
            cout << "Your input sucks." << endl;
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            bool itWasThere = false;
            for (int i = 0; i < SIZE; i++) {
                if (theArr[i] == numb)
                    itWasThere = true;
            }


            if (itWasThere)
                cout << "\n hey it was there neat" << endl;
            else
                cout << "nope" << endl;
        }

        cout << "\n Do you want to continue? y/n" << endl;
        char response;
        cin >> response;
        if (cin.fail()) {
            cout << "Your input sucks." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            if (response != 'Y' or response != 'y') {
                searchNumbers = false;
            }
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
