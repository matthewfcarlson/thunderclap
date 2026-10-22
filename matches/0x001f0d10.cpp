#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

class Function_1f0d10 {
  public:
    Function_1f0d10(void* a, int n);
    virtual void f0();
    char pad[12];
};

class Method4_1f0d10 : public Function_1f0d10 {
  public:
    Method4_1f0d10(void* a, int b);
    char m10, m11, m12, m13;
    int pad14;
    char m18;
    char pad19[3];
    int m1c;
};

extern "C" char __cdecl Lookup(const char* s);

Method4_1f0d10::Method4_1f0d10(void* a, int b) : Function_1f0d10(a, 4) {
    m1c = b;
    m18 = Lookup((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    m10 = Lookup((const char*)((hulk_intptr)((char*)&DAT_0049cad8)));
    m11 = Lookup((const char*)((hulk_intptr)((char*)&DAT_0049cad8)));
    m12 = Lookup((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    m13 = Lookup((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}
