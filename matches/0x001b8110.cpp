#include "decls/data/game/global.h"
// data: gFlag_1b8110 = DAT_004e222c

extern "C" int __cdecl GetValue();
class Sub_1b8110 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int);
};
class Obj_1b8110 {
  public:
    char pad0[4];
    int value;
    char pad8;
    unsigned char active;
    char padA[2];
    Sub_1b8110* sub;
    char pad10[0x120];
    unsigned char pending;
    char pad131[3];
    int arg;
    void target(int);
};
void Obj_1b8110::target(int x) {
    if (sub) {
        active = 0;
        sub->v8();
        value = GetValue() + x;
        (*(unsigned char*)&DAT_004e222c) = 1;
        if (pending && sub) {
            sub->v10(arg);
            pending = 0;
        }
    }
}