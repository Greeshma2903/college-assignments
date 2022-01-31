/*
Write a C++ program which reads a text from keyboard and display the following
information on screen in 3 column format
1. Number of lines
2. Number of words
3. Number of characters
4. Number of spaces
Strings should be left justified and numbers to be right justified. Use suitable field width
*/

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[100], ch;
    int i, noLines, noChar, noWords, noSpaces;
    cout << "Enter some text:";
    cin.getline(str, sizeof(str), '#');
    noLines = 0;
    noWords = 0;
    noChar = 0;
    noSpaces = 0;
    for (i = 0; i < strlen(str); ++i)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '#')
        {
            noWords++;
        }
        if (str[i] == ' ')
            noSpaces++;
        if (str[i] == '\n')
            noLines++;
        noChar++;
    }
    noWords++;
    noLines++;
    cout << endl;
    cout.setf(ios::left, ios::adjustfield);
    cout.fill(' ');
    cout.width(24);
    cout << "Number of Lines";
    cout.width(24);
    cout << "Number of Words";
    cout.width(24);
    cout << "Number of Characters";
    cout.width(24);
    cout << "Number of Spaces" << endl;
    cout.setf(ios::right, ios::adjustfield);
    cout.fill(' ');
    cout.width(24);
    cout << noLines;
    cout.width(24);
    cout << noWords;
    cout.width(24);
    cout << noChar;
    cout.width(24);
    cout << noSpaces;

    return 0;
}