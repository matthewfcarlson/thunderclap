#include "decls/data/game/global.h"

class Function_7d050 {
  public:
    Function_7d050(const char*, int);
    virtual void f();
};
extern "C" unsigned char __cdecl check(const char*);
class Method3 : public Function_7d050 {
  public:
    Method3(const char*, int);
    virtual void f();
    char pad[12];
    unsigned char x, y, z;
    char pad2[5];
    unsigned char w;
    char pad3[3];
    int n;
};
Method3::Method3(const char* s, int k) : Function_7d050(s, 3) {
    n = k;
    w = check(((const char*)&DAT_0048e100));
    x = check(((const char*)&DAT_0048e0f0));
    y = check(((const char*)&DAT_0048e134));
    z = check(((const char*)&DAT_0048e0e4));
}