#include "compat/ptr.h"
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
    bool Do(int, Temp_290ad0*);
    bool Run(int);
};
bool Obj_290ad0::Run(int arg) {
    Temp_290ad0 t;
    t.Init();
    t.value = 0;
    bool r = Do(arg, &t);
    if (t.value) {
        Free((void*)t.value);
        t.value = 0;
    }
    t.Fin();
    return r;
}
