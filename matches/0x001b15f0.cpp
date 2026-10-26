#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

typedef unsigned char u8;
struct CtorV_001d0480 {
    CtorV_001d0480(int, int);
    virtual void v_001d0480();
};
u8 __cdecl query(const char*);
class Function_1b15f0 : public CtorV_001d0480 {
  public:
    Function_1b15f0(int n) : CtorV_001d0480(n, 2) { }
};
class Function2 : public Function_1b15f0 {
  public:
    virtual void f();
    char pad[12];
    u8 x;
    u8 y;
    char pad2[6];
    u8 z;
    char pad3[3];
    int data;
    Function2(int, int);
};
Function2::Function2(int n, int d) : Function_1b15f0(n) {
    data = d;
    z = query(((const char*)&DAT_0048e100));
    x = query(((const char*)&DAT_0048e128));
    y = query(((const char*)&DAT_0048e128));
}