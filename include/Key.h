#ifndef KEY_H
#define KEY_H
#include <string>

class Key
{
    public:
        Key();
        ~Key();
        short getValue(short position);
        void setValue(short position, short valueIn);
        void stringToKey(std::string text);
        std::string keyToString();
        Key& operator+(Key &in2);
        Key& operator-(Key &in2);

    protected:

    private:
        short value[64];
};

#endif // KEY_H
