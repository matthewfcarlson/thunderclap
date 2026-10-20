// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_000e13c0 @ 0x000e13c0
#include "compat/ptr.h"
struct Matrix {
    float m[16];
    void FUN_0022b980();
};
void* __cdecl FUN_0008d6d0(hulk_uintptr size);

class FEAnimation {
public:
    virtual void v0();
    char* name;
    int f08;
    int f0c;
    int f10;
    Matrix matrix;
    float scale;
    int f58;
    char f5c;
    FEAnimation(int arg, const char* text);
};

FEAnimation::FEAnimation(int arg, const char* text) {
    name = 0;
    f08 = arg;
    scale = 1.0f;
    f10 = 0;
    matrix.FUN_0022b980();
    f58 = 0;
    if (text != 0) {
        unsigned int len = 0;
        while (text[len] != 0)
            len++;
        len++;
        char* copy = (char*)FUN_0008d6d0(len);
        name = copy;
        const char* src = text;
        char c;
        do {
            c = *src++;
            *copy++ = c;
        } while (c != 0);
    }
    f0c = 0;
    f5c = 0;
}
