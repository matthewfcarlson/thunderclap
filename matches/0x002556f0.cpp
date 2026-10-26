#include "decls/data/engine/audio.h"
// data: gData_2556f0 = DAT_004e7508

typedef unsigned char byte_2556f0;
struct Sub1_2556f0 {
    void m();
};
struct Sub2_2556f0 {
    void m();
};
struct Sub3_2556f0 {
    void m();
};
void __cdecl f4(void*, void*);
struct SeqEventCrossFade {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual SeqEventCrossFade* vfunc_4(byte_2556f0 p);
    char pad[0x2c - 4];
};
SeqEventCrossFade* SeqEventCrossFade::vfunc_4(byte_2556f0 p) {
    reinterpret_cast<Sub1_2556f0*>((char*)this + 0x2c)->m();
    reinterpret_cast<Sub2_2556f0*>((char*)this + 0x1c)->m();
    reinterpret_cast<Sub3_2556f0*>(this)->m();
    if (p & 1)
        f4(((char*)&DAT_004e7508), this);
    return this;
}
