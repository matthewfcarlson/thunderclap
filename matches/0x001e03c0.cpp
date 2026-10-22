#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

struct Function_1e03c0 {
    Function_1e03c0(int a, int b);
    virtual void F0();
    int pad[3];
};

char ParseArg(const char* s);

struct Method6 : Function_1e03c0 {
    Method6(int a, int b);
    virtual void F0();
    char c10, c11, c12, c13, c14, c15;
    char pad16[2];
    char c18;
    char pad19[3];
    int m1c;
};

Method6::Method6(int a, int b) : Function_1e03c0(a, 6) {
    m1c = b;
    c18 = ParseArg((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    c10 = ParseArg((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    c11 = ParseArg((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    c12 = ParseArg((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    c13 = ParseArg((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    c14 = ParseArg((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    c15 = ParseArg((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}
