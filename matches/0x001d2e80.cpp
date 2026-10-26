#include "decls/data/game/unknown.h"

struct Obj_1d2e80 {
    char pad[8];
    void* m;
    void F1d1cb0();
    bool target();
};
extern int __cdecl FUN_00212d70(void*);
extern void __cdecl FUN_00213380(void*, const char*, int);
extern void __cdecl FUN_00213600(void*, int);
extern int __cdecl FUN_00212f00(void*, int);
extern int __cdecl FUN_00212d80(void*, int);
bool Obj_1d2e80::target() {
    int v = FUN_00212d70(m);
    F1d1cb0();
    FUN_00213380(m, DAT_003f8eb0, 5);
    FUN_00213600(m, -2);
    int r = FUN_00212f00(m, -1);
    if (r != 5) {
        FUN_00212d80(m, v);
        return false;
    }
    return true;
}