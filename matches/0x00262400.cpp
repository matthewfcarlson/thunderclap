#include "compat/ptr.h"
class Obj_262400 {
  public:
    unsigned int A();
    char* B();
};
class P2_262400 {
  public:
    void SetExt(char*);
};

void* FUN_00262400(Obj_262400* obj, P2_262400* p2) {
    if (obj->A() > 0) {
        char* start = obj->B();
        char* p = (char*)obj->A();
        p += (hulk_uintptr)obj->B();
        while (p >= start) {
            if (*p == '.') {
                p2->SetExt(p + 1);
                return (void*)p2;
            }
            --p;
        }
    }
    return (void*)p2;
}
