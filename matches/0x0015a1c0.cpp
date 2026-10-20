#include "compat/ptr.h"
extern "C" char DAT_00414420[];
extern void* __cdecl Alloc(hulk_uintptr);
class Track {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[8];
    int a;
    int b;
    unsigned char c, d, e;
    void Init();
    void* Make();
};
void* Track::Make() {
    Track* p = (Track*)Alloc(0x18);
    if (p) {
        p->Init();
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = 0;
        p->e = 0;
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00414420);
        return p;
    }
    return 0;
}
