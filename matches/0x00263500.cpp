#include "decls/data/engine/unknown.h"

typedef unsigned char bool8;
struct Obj_263500 {
    int pad[6];
    int a;
    int b;
};
extern bool8 __cdecl Check(int, const char*, ...);
extern "C" bool8 __cdecl FUN_0025ac30(int*, int, int);
extern "C" int __cdecl FUN_00263500(int* p, Obj_263500* o) {
    int a;
    int b;
    if (o) {
        a = o->a;
        b = o->b;
    } else {
        a = 0;
        b = 0;
    }
    if (Check(*p, DAT_0042ae80) && FUN_0025ac30(p, a, b))
        return 1;
    return 0;
}