#include "compat/ptr.h"
#include "gen/owners.h"
struct Temp_290ad0 {
    char pad[8];
    hulk_intptr value;
    int extra;
    void Init();
    void Fin();
};
extern void Free(void*);
class Obj_290ad0 {
  public:
    bool Run(int);
};
bool Obj_290ad0::Run(int arg) {
    Temp_290ad0 t;
    t.Init();
    t.value = 0;
    bool r = ((owners::Buffer_2909c0 *)this)->FUN_002909c0((unsigned)arg, (hulk_uintptr)(Temp_290ad0 *)(&t));
    if (t.value) {
        Free((void*)t.value);
        t.value = 0;
    }
    t.Fin();
    return r;
}
