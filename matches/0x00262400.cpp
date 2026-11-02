#include "compat/ptr.h"
class Obj_262400 {
  public:
    hulk_uintptr A();
    char* B();
};
class P2_262400 {
  public:
    void SetExt(char*);
};

extern "C" void* FUN_00262400(void * obj, void * p2) {
    if (((Obj_262400 *)obj)->A() > 0) {
        char* start = ((Obj_262400 *)obj)->B();
        char* p = (char*)((Obj_262400 *)obj)->A();
        p += (hulk_uintptr)((Obj_262400 *)obj)->B();
        while (p >= start) {
            if (*p == '.') {
                ((P2_262400 *)p2)->SetExt(p + 1);
                return (void*)((P2_262400 *)p2);
            }
            --p;
        }
    }
    return (void*)((P2_262400 *)p2);
}
