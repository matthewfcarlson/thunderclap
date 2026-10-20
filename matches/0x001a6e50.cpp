#include "compat/ptr.h"
extern "C" char DAT_0048d5bc[];
extern "C" char DAT_004c26a4[];
class Obj_1a6e50 {
  public:
    Obj_1a6e50* Get();
    Obj_1a6e50* Target();
};
extern int __cdecl Find(Obj_1a6e50*, int, const char*, const char*, int);
Obj_1a6e50* Obj_1a6e50::Target() {
    Obj_1a6e50* p = Get();
    while (p && Find(p, 0, (const char*)((hulk_intptr)DAT_0048d5bc), (const char*)((hulk_intptr)DAT_004c26a4), 0) == 0)
        p = Get();
    return p;
}