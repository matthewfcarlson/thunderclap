#include "compat/ptr.h"
typedef unsigned int u32_2e59b0;
class Obj_2e59b0 {
  public:
    char pad[12];
    void Work(u32_2e59b0);
};
u32_2e59b0 __cdecl target(u32_2e59b0 p, u32_2e59b0 count, u32_2e59b0 arg) {
    if (count != 0) {
        Obj_2e59b0* q = (Obj_2e59b0*)p;
        u32_2e59b0 i = count;
        do {
            if (q)
                q->Work(arg);
            q = (Obj_2e59b0*)((char*)q + 12);
            i--;
        } while (i != 0);
        return (hulk_uintptr)q;
    }
    return p;
}
