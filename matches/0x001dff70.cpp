#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

class Base_1dff70 {
  public:
    Base_1dff70(int a, int b);
    virtual void f0();
    char pad[0x0c];
};

class Derived_1dff70 : public Base_1dff70 {
  public:
    Derived_1dff70(int a, int b);
    virtual void f0();
    char m10, m11, m12, m13;
    int m14;
    char m18;
    char m19[3];
    int m1c;
};

extern char GetFlag(const char* s);

void Derived_1dff70::f0() {}

Derived_1dff70::Derived_1dff70(int a, int b) : Base_1dff70(a, 4) {
    m1c = b;
    m18 = GetFlag((const char*)((int)((char*)&DAT_0048e100)));
    m10 = GetFlag((const char*)((int)((char*)&DAT_0048e134)));
    m11 = GetFlag((const char*)((int)((char*)&DAT_0048e128)));
    m12 = GetFlag((const char*)((int)((char*)&DAT_0048e128)));
    m13 = GetFlag((const char*)((int)((char*)&DAT_0048e128)));
}
