#include "compat/ptr.h"
#include "gen/owners.h"
class Builder {
  public:
    void Make(void*);
};
class Dest_36be0 {
  public:
};
class Obj_36be0 {
  public:
    char pad[0x10];
    Builder* builder;
    char pad2[0x1ca0 - 0x14];
    int m1ca0;
    void Run(int);
};
void Obj_36be0::Run(int arg) {
    char local[12];
    hulk_intptr value = m1ca0;
    if (value) {
        Dest_36be0* p = (Dest_36be0*)(value + 0x58);
        if (p) {
            builder->Make(local);
            ((owners::C_fddf0 *)p)->FUN_000fddf0((void *)(hulk_uintptr)(int)arg, (unsigned *)local);
        }
    }
}