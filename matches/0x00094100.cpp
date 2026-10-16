#include "decls/data/game/global.h"

class Base_94100 {
  public:
    Base_94100(int a, int b);
    virtual void f0();
    char pad[0xc];
};

extern "C" char __cdecl Lookup(const char* s);

class Derived_94100 : public Base_94100 {
  public:
    Derived_94100(int a, int b);
    virtual void f0();
    char c10, c11, c12, c13, c14, c15;
    char pad2[2];
    char c18;
    char pad3[3];
    int m1c;
};

void Base_94100::f0() {}
void Derived_94100::f0() {}

Derived_94100::Derived_94100(int a, int b) : Base_94100(a, 6) {
    m1c = b;
    c18 = Lookup((const char*)((int)((char*)&DAT_0048e100)));
    c10 = Lookup((const char*)((int)((char*)&DAT_0048e134)));
    c11 = Lookup((const char*)((int)((char*)&DAT_0048e0f0)));
    c12 = Lookup((const char*)((int)((char*)&DAT_0048e0f0)));
    c13 = Lookup((const char*)((int)((char*)&DAT_0048e0f0)));
    c14 = Lookup((const char*)((int)((char*)&DAT_0048e0f0)));
    c15 = Lookup((const char*)((int)((char*)&DAT_0048e134)));
}
