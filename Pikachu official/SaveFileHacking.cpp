#include "Header.h"

void loadFileHacking(string fileName, savefile& a)
{
    ifstream inFile(fileName, ios::binary);
    inFile.read((char*)&a.mask, 1);
    inFile.read((char*)&a.name, 50);
    inFile.read((char*)&a.password, 50);
    char ignore[500];
    inFile.seekg(104, ios::beg);
    // record
    for (int i = 0; i < 5; i++)
    {
        inFile.read((char*)&a.record[i].date.dd, 4);
        inFile.read((char*)&a.record[i].date.mm, 4);
        inFile.read((char*)&a.record[i].date.yy, 4);
        inFile.read((char*)&a.record[i].points, 4);
        inFile.read((char*)&ignore, 500);
    }
    // state 
    for (int i = 0; i < 5; i++)
    {
        inFile.read((char*)&a.state[i].p, 4);
        inFile.read((char*)&a.state[i].q, 4);
        inFile.read((char*)&a.state[i].p_, 4);
        inFile.read((char*)&a.state[i].q_, 4);
        inFile.read((char*)&a.state[i].board, 999); 
        inFile.read((char*)&a.state[i].file_background, 100);
        inFile.read((char*)&ignore, 500);
    }
    inFile.close();
}

string operatorXor(string a, string mask) // xor
{
    string c;
    for (int i = 0; i < a.length(); i++)
    {
        if ((a[i] == '1' && mask[i] == '1') || (a[i] == '0' && mask[i] == '0'))
            c += '0';
        else
            c += '1';
    }
    return c;
}

string binary(int a) // decimal to binary
{
    string s;
    while (a)
    {
        s += to_string(a % 2);
        a /= 2;
    }
    for (int i = s.length(); i < 8; i++)
    {
        s += '0';
    }
    return s;
} 

int decimal(string a) // binary to decimal
{
    int x = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '1')
            x += pow(2, i);
    }
    return x;
}

string sovleXor(char a[], string mask) 
{
    string s;
    for (int i = 0; i < strlen(a); i++)
    {
        string tmp;
        tmp = binary(int(a[i]));
        tmp = operatorXor(tmp, mask);
        s += char(decimal(tmp));
    }
    return s;
}



