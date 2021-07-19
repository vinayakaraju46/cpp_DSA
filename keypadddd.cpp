#include <iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string n;
    vector<string> o;
    int i, x(0);
    map<string, char>character;

    {
        character["2"] = 'A';
        character["22"] = 'B';
        character["222"] = 'C';
        character["3"] = 'D';
        character["33"] = 'E';
        character["333"] = 'F';
        character["4"] = 'G';
        character["44"] = 'H';
        character["444"] = 'I';
        character["5"] = 'J';
        character["55"] = 'K';
        character["555"] = 'L';
        character["6"] = 'M';
        character["66"] = 'N';
        character["666"] = 'O';
        character["7"] = 'P';
        character["77"] = 'Q';
        character["777"] = 'R';
        character["7777"] = 'S';
        character["8"] = 'T';
        character["88"] = 'U';
        character["888"] = 'V';
        character["9"] = 'W';
        character["99"] = 'X';
        character["999"] = 'Y';
        character["9999"] = 'Z';
        character["0"] = ' ';
    }

    cout << "Please enter the message: ";
    cin >> n;

    for(i = 0; i < 17; i++)
    {
        if(i < 16 && n.at(i) == n.at(i + 1))
            o[x] = n.at(i) + n.at(i + 1);
        else
            x++;

        o[x] = n.at(i);
    }

    for(x = 0; x < o.size(); x++)
        cout << "Output message: " << character[o[x]] << endl;

    cout << "Count: " << o.size() << endl;
    return 0;
}