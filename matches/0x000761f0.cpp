#include "compat/ptr.h"
extern "C" char DAT_003fbd14[];
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
struct CDamageTrack {
    int vptr;
    int pad4;
    int pad8;
    int x;
    int y;
    int z;
    void ctor();
};
extern "C" void* __cdecl alloc(unsigned int);
void* __cdecl target() {
    CDamageTrack* p = (CDamageTrack*)alloc(0x18);
    if (p) {
        p->ctor();
        p->vptr = ((hulk_intptr)DAT_003fbd14);
        p->x = 0;
        p->y = 0;
        p->z = 0;
        p->pad8 = 1;
        return p;
    }
    return 0;
}