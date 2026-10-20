#include "compat/ptr.h"
extern "C" char DAT_0048d5bc[];
extern "C" char DAT_004a15cc[];
class Owner_1a6e10 {
  public:
    void* Get();
    void* Find();
};
extern int Check(void*, int, void*, void*, int);
void* Owner_1a6e10::Find() {
    void* p = Get();
    while (p != 0 && Check(p, 0, (void*)((hulk_intptr)DAT_0048d5bc), (void*)((hulk_intptr)DAT_004a15cc), 0) == 0) {
        p = Get();
    }
    return p;
}