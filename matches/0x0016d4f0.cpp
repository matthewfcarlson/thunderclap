#include "compat/ptr.h"
extern "C" char DAT_004166b8[];
extern "C" void* alloc(unsigned int);
class Condition {
  public:
    void init(int);
};
class Template_16d4f0 {
  public:
    char pad[0x14];
};
void* target(Template_16d4f0* self) {
    Condition* p = (Condition*)alloc(0x14);
    if (p) {
        p->init(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004166b8);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}