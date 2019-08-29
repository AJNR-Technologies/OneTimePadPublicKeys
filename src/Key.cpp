#include "Key.h"
#include <iostream>

using namespace std;

Key::Key()
{
    for(int i = 0; i<64; i++){
        value[i] = 0;
    }
}

Key::~Key()
{
    for(int i = 0; i<64; i++){
        value[i] = 0;
    }
}

short Key::getValue(short position)
{
    return value[position];
}

void Key::setValue(short position, short valueIn)
{
    value[position] = valueIn;
}

void Key::stringToKey(std::string text)
{
    std::string error = "Error ";
    if(text.length() != 64){
        error += "1: key length is invalid";
        throw error;
    }

    short aux = 0;
    for(int i=0; i<64; i++){
        switch (text[i]){
        case '0':
            aux = 0;
            break;
        case '1':
            aux = 1;
            break;
        case '2':
            aux = 2;
            break;
        case '3':
            aux = 3;
            break;
        case '4':
            aux = 4;
            break;
        case '5':
            aux = 5;
            break;
        case '6':
            aux = 6;
            break;
        case '7':
            aux = 7;
            break;
        case '8':
            aux = 8;
            break;
        case '9':
            aux = 9;
            break;
        case 'A':
        case 'a':
            aux = 10;
            break;
        case 'B':
        case 'b':
            aux = 11;
            break;
        case 'C':
        case 'c':
            aux = 12;
            break;
        case 'D':
        case 'd':
            aux = 13;
            break;
        case 'E':
        case 'e':
            aux = 14;
            break;
        case 'F':
        case 'f':
            aux = 15;
            break;
        default:
            error += "2: invalid character at";
            error += std::to_string(i);
            throw error;
        }
        this->setValue(i, aux);
    }
}

std::string Key::keyToString()
{
    std::string error = "Error ";
    std::string toReturn = "";
    short value = 0;
    for(int i = 0; i<64; i++){
        value = this->getValue(i);
        switch (value){
        case 0:
            toReturn += "0";
            break;
        case 1:
            toReturn += "1";
            break;
        case 2:
            toReturn += "2";
            break;
        case 3:
            toReturn += "3";
            break;
        case 4:
            toReturn += "4";
            break;
        case 5:
            toReturn += "5";
            break;
        case 6:
            toReturn += "6";
            break;
        case 7:
            toReturn += "7";
            break;
        case 8:
            toReturn += "8";
            break;
        case 9:
            toReturn += "9";
            break;
        case 10:
            toReturn += "A";
            break;
        case 11:
            toReturn += "B";
            break;
        case 12:
            toReturn += "C";
            break;
        case 13:
            toReturn += "D";
            break;
        case 14:
            toReturn += "E";
            break;
        case 15:
            toReturn += "F";
            break;
        default:
            error += "2: invalid character at";
            error += std::to_string(i);
            throw error;
        }
    }

    return toReturn;
}

Key& Key::operator+(Key &in2)
{
    Key *toReturn = new Key();
    short aux;
    for(int i = 0; i<64; i++){
        aux = (this->getValue(i) + in2.getValue(i));
        while(aux>15){
            aux-=16;
        }
        toReturn->setValue(i, aux);
        aux = 0;
    }

    return *toReturn;
}

Key& Key::operator-(Key &in2)
{
    Key *toReturn = new Key();
    short aux;
    for(int i = 0; i<64; i++){
        aux = (this->getValue(i) - in2.getValue(i));
        while(aux<0){
            aux+=16;
        }
        toReturn->setValue(i, aux);
        aux = 0;
    }
    return *toReturn;
}
