#include "decls/data/engine/core.h"
// data: g_lock_275780 = DAT_0052a1c8, g_pool_275780 = DAT_0052a1e4

extern void* g_vftable_275780[];
extern void* g_base_vftable[];
class Pool_275780 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*);
};
void Lock(void*);
void Unlock(void*);
class B_275780 {
  public:
    virtual void v0();
    virtual void v1();
};
class Big_275780 {
  public:
    virtual void v0();
    virtual void v1();
    B_275780 sub;
    char pad[0xc];
    int cnt;
};
class DriveMediaRequest_275780 {
  public:
    void* vptr;
    char pad[4];
    Big_275780* m8;
    DriveMediaRequest_275780* f0(unsigned char flags);
};
DriveMediaRequest_275780* DriveMediaRequest_275780::f0(unsigned char flags) {
    Big_275780* p = m8;
    vptr = g_vftable_275780;
    p->sub.v0();
    m8->cnt--;
    m8->sub.v1();
    m8->v1();
    vptr = g_base_vftable;
    if (flags & 1) {
        Lock(((char*)&DAT_0052a1c8));
        (*(Pool_275780**)&DAT_0052a1e4)->Free(this);
        Unlock(((char*)&DAT_0052a1c8));
    }
    return this;
}
