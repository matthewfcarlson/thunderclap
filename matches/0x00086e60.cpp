#include "decls/data/game/unknown.h"
// data: gName = DAT_0048e128

extern "C" unsigned char __cdecl readChar(const char*);
class Function_86e60 {
  public:
    Function_86e60(int, int);
    virtual void f();
    char pad[0x14];
};
class Function2 : public Function_86e60 {
  public:
    Function2(int, int);
    virtual void f();
    char val18;
    char pad2[3];
    int value;
};
Function2::Function2(int a, int b) : Function_86e60(a, 2) {
    value = b;
    val18 = readChar(((char*)&DAT_0048e128));
    *(unsigned char*)((char*)this + 0x10) = readChar(((char*)&DAT_0048e128));
    *(unsigned char*)((char*)this + 0x11) = readChar(((char*)&DAT_0048e128));
}