#include "decls/data/game/global.h"

class Function_1069c0 {
  public:
    virtual void f();
    Function_1069c0(const char*, int);
};
extern unsigned char __cdecl get(const char*);
class Method3 : public Function_1069c0 {
  public:
    virtual void f();
    char pad[12];
    unsigned char a, b, c;
    char pad2[5];
    unsigned char d;
    char pad3[3];
    int value;
    Method3(const char*, int);
};
Method3::Method3(const char* p, int v) : Function_1069c0(p, 3) {
    value = v;
    d = get(((const char*)&DAT_0048e0e4));
    a = get(((const char*)&DAT_0048e0f0));
    b = get(((const char*)&DAT_0048e0e4));
    c = get(((const char*)&DAT_0048e134));
}