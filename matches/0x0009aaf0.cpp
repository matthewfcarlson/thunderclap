#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" char DAT_00404c50[];
class Base_9aaf0 {
  public:
    void Init(int, int);
};
extern unsigned char __cdecl GetValue(const char*);
class Obj_9aaf0 : public Base_9aaf0 {
  public:
    int vt;
    char pad4[0x0c];
    unsigned char b10, b11, b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    int field1c;
    Obj_9aaf0(int a, int b);
};
Obj_9aaf0::Obj_9aaf0(int a, int b) {
    Init(a, 3);
    vt = ((hulk_intptr)DAT_00404c50);
    field1c = b;
    b18 = GetValue((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    b10 = GetValue((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b11 = GetValue((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b12 = GetValue((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
}