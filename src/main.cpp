#include <iostream>
#include <Key.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

void readKey(Key & key1){

    string texto = "";
    bool error = false;
    do{
        error = false;
        cout<<"Insert public Key (64)"<<endl;
        getline(cin, texto);
        try{
            key1.stringToKey(texto);
        }catch(string es){
            cout<<es<<endl;
            error = true;
        }catch(exception ex){
            cout<<ex.what()<<endl;
            error = true;
        }catch(...){
            error = true;
        }
    }while(error);
}

void saveFiles(Key key, Key password){
    ofstream cerFile;
    ofstream keyFile;
    Key out = Key();
    out = key + password;
    cerFile.open("file.cer");
    keyFile.open("file.key");

    cerFile<<out.keyToString();
    keyFile<<password.keyToString();

    cerFile.close();
    keyFile.close();

}

void readFiles(Key &key, Key & password){
    string error = "Error ";
    ifstream cerFile("file.cer");
    ifstream keyFile("file.key");

    char *getChar = new char[65];

    if(cerFile.fail()){
        error += "4: fail to open file.cer";
        throw error;
    }else{
        cerFile.getline(getChar, 65);
    }

    key.stringToKey(string(getChar));

    if(keyFile.fail()){
        error += "5: fail to open file.key";
        throw error;
    }else{
        keyFile.getline(getChar, 65);
    }

    password.stringToKey(string(getChar));

    for(int i = 0; i< 64; i++){
        getChar[i] = ' ';
    }

    key = key - password;

    cerFile.close();
    keyFile.close();
}

void randomKey(Key &key){
    short random = 0;
    for(short i = 0; i<64; i++){
        random = rand() % 16;
        key.setValue(i, random);
    }
}

void getInt(int &number){
    string error = "Error ";
    string text = "";
    getline(cin, text);
    try{
        number = stoi(text);
    }catch(...){
        error += "6: fail to get number, retry";
        number = 0;
        throw error;
    }
}

int main(){
    srand(time(NULL));
    Key *key1 = new Key();
    Key *password = new Key();
    int selection = 0;

    do{
        delete key1;
        key1 = new Key();
        delete password;
        password = new Key();
        system("cls");
        cout<<"1: create cer/key"<<endl;
        cout<<"2: read cer/key"<<endl;
        cout<<"3: exit"<<endl;
        getInt(selection);
        switch(selection){
            case 1:
                readKey(*key1);
                randomKey(*password);
                saveFiles(*key1, *password);
                try{
                    cout<<"Key:      "<<key1->keyToString()<<endl;
                    cout<<"Password: "<<password->keyToString()<<endl;
                }catch(string text){
                    cout<<text<<endl;
                }catch(exception ex){
                    cout<<ex.what()<<endl;
                }catch(...){

                }
                system("pause");
                break;
            case 2:
                try{
                    readFiles(*key1, *password);
                    cout<<"Key:      "<<key1->keyToString()<<endl;
                    cout<<"Password: "<<password->keyToString()<<endl;
                }catch(string es){
                    cout<<es<<endl;
                }catch(exception ex){
                    cout<<ex.what()<<endl;
                }catch(...){

                }
                system("pause");
                break;
            case 3:
                break;
            default:
                cout<<"Invalid option, retry"<<endl;
        }
        Sleep(300);
    }while(selection != 3);

}
