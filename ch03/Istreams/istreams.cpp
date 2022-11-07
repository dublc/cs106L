#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// read numbers from a file
void readNumbers()
{
    // Create our ifstream and make it open the file
    // Something to store values we get from the stream
    // Extract next number from input
    // If input is in a fail state, either a value couldn't
    // be converted, or we are at the end of the file.
    // print whatever we read

    // std::ifstream in("res/numbers.txt");

    // int num;
    // while (in >> num)
    //     cout << num << endl;

    // if (in.eof())
    //     cout << "Fail to get number: " << num << endl;
    std::ifstream input("res/numbers.txt");

    // This will store the values as we get them form the stream
    int value;
    while(true) {
        // Extract next number from input
        input >> value;

        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.

        if(input.fail())
            break;
        cout << "Value read: " << value << endl;
    }
}

// read a single word at a time from a file
void readHaikuWord()
{
    // Create our ifstream and make it open the file
    // Something to store values we get from the stream
    // Extract next word from input
    // If input is in a fail state, either a value couldn't
    // be converted, or we are at the end of the file.
    // print whatever we read

    std::ifstream in("res/haiku.txt");
    string word;
    while (true)
    {
        in >> word;
        if (in.fail())
            break;
        cout << "Word is: " << word << endl;
    }
}

void readHaikuLine()
{
    // Create our ifstream and make it open the file
    // Something to store the lines as we get them form the stream
    // If input is in a fail state, either a value couldn't
    // be converted, or we are at the end of the file.
    // print whatever we read

    std::ifstream in("res/haiku.txt");
    string line;
    while (true)
    {
        std::getline(in, line);
        if (in.fail())
            break;
        cout << "Line is: " << line << endl;
    }
}

// function for us to play around with cin
void playground()
{
    string line;
    std::ifstream in("res/haiku.txt");
    while (std::getline(in, line))
    {
        // if (in.eof())
        // {
        //     cout << "eof" << endl;
        //     // break;
        // }
        // else if (in.fail())
        // {
        //     cout << "fail" << endl;
        //     // break;
        // }
        // else
        cout << line << endl;
        // cout << in.eof() << in.fail() << endl;
    }
    cout << in.eof() << in.fail() << endl;
}

int main()
{
    readNumbers();

    cout << "=============================================================================" << endl;
    readHaikuWord();

    cout << "=============================================================================" << endl;
    readHaikuLine();
    return 0;
}
