#include "compat/ptr.h"
typedef unsigned char u8_23ec10;
extern int spawn_vftable;
struct A_23ec10 {
    void init();
};
struct B_23ec10 {
    void init();
};
struct SpawnTrack_23ec10 {
    void init();
};
namespace fight {
struct Track {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};
struct SpawnTrack : Track {
    char pad[0x20 - sizeof(Track)];
    SpawnTrack* vfunc_5(u8_23ec10);
};
} // namespace fight
fight::SpawnTrack* fight::SpawnTrack::vfunc_5(u8_23ec10 flag) {
    *(hulk_intptr*)this = (hulk_intptr)&spawn_vftable;
    ((A_23ec10*)((char*)this + 0x20))->init();
    ((B_23ec10*)((char*)this + 0x14))->init();
    ((SpawnTrack_23ec10*)this)->init();
    if (flag & 1) {
        extern void del(fight::SpawnTrack*);
        del(this);
    }
    return this;
}