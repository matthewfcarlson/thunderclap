#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern unsigned char __cdecl GetFlag(const char*);
class Function_2c700 {
  public:
    virtual void V();
    Function_2c700(int a, int b) throw();
    char pad[0x1c - 4];
};
class Method1 : public Function_2c700 {
  public:
    virtual void V();
    Method1(int a, int b) throw();
    unsigned char x;
};
Method1::Method1(int a, int b) throw() : Function_2c700(a, 1) {
    *(int*)((char*)this + 0x1c) = b;
    *(unsigned char*)((char*)this + 0x18) = GetFlag(((char*)&DAT_0048e128));
    *(unsigned char*)((char*)this + 0x10) = GetFlag(((char*)&DAT_0048e0f0));
}