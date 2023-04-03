#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include "Header.h"

using namespace std;
#pragma warning(disable : 4996)

void loadFileHacking(string fileName, savefile& a)
{
    ifstream inFile(fileName, ios::binary);
    inFile.read((char*)&a.mask, 1);
    inFile.read((char*)&a.name, 50);
    inFile.read((char*)&a.password, 50);
    char ignore[500];
    inFile.read((char*)&ignore, 500);
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

string binary(int a) // doi tu decimal qua binary
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
} // 

int decimal(string a) // doi tu binary qua decimal
{
    int x = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '1')
            x += pow(2, i);
    }
    return x;
}
string sovleXor(char a[], string mask) // chuoi can doi
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
void changeInfor(savefile& a, Player*& bht) // chinh sua thong tin tuy thich
{
    // mask
    string maskbin = binary(int(a.mask));
    // name
    strcpy(bht->userName, sovleXor(a.name, maskbin).c_str());

    // player point and time
    bht->Easy = new InforMatches;
    bht->Easy->bestPoint = 999;
    bht->Easy->bestTime = 1;
    bht->Hard = new InforMatches;
    bht->Hard->bestPoint = 999;
    bht->Hard->bestTime = 1;
    // record
    for (int i = 0; i < 5; i++)
    {
        a.record[i].date.dd = 27 + i;
        a.record[i].date.mm = i + 1;
        a.record[i].date.yy = 2023;
        a.record[i].points = 999;
    }
    // state
    for (int i = 0; i < 5; i++)
    {
        a.state[i].p = 1;
        a.state[i].q = 1;
        a.state[i].p_ = 1;
        a.state[i].q_ = 1;
        a.state[i].board;
        a.state[i].file_background;
    }
}
void saveFileHacking(string nameFile, savefile a) // luu file hack da chinh sua vo "Template.bin"
{
    ofstream outFile(nameFile, ios::binary);
    char ignore[500];
    outFile.write((char*)&a.mask, 1);
    outFile.write((char*)&a.name, 50);
    outFile.write((char*)&a.password, 50);
    outFile.write((char*)&ignore, 500);
    // record
    for (int i = 0; i < 5; i++)
    {
        outFile.write((char*)&a.record[i].date.dd, 4);
        outFile.write((char*)&a.record[i].date.mm, 4);
        outFile.write((char*)&a.record[i].date.yy, 4);
        outFile.write((char*)&a.record[i].points, 4);
        outFile.write((char*)&ignore, 500);
    }
    // state 
    for (int i = 0; i < 5; i++)
    {
        outFile.write((char*)&a.state[i].p, 4);
        outFile.write((char*)&a.state[i].q, 4);
        outFile.write((char*)&a.state[i].p_, 4);
        outFile.write((char*)&a.state[i].q_, 4);
        outFile.write((char*)&a.state[i].board, 999);
        outFile.write((char*)&a.state[i].file_background, 100);
        outFile.write((char*)&ignore, 500);
    }
    outFile.close();
}
