#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

class Function_2c8b0 {
  public:
    Function_2c8b0(const char*, int);
    virtual void f();
};
extern "C" char __cdecl lookup(const char*);
class Method3 : public Function_2c8b0 {
  public:
    Method3(const char*, int);
    char pad[12];
    char a, b, c;
    char pad2[5];
    char d;
    char pad3[3];
    int val;
};
Method3::Method3(const char* name, int x) : Function_2c8b0(name, 3) {
    val = x;
    d = lookup(((const char*)&DAT_0048e100));
    a = lookup(((const char*)&DAT_0048e0f0));
    b = lookup(((const char*)&DAT_0048e128));
    c = lookup(((const char*)&DAT_0048e0f0));
}