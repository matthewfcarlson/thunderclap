// Same code shape as 0x0024fee0 (propagated; names are from that function)
#include "gen/audio.h"
#include "decls/data/engine/audio.h"
class SeqEvent_2515e0 {
  public:
    char pad[0x14];
};
class SeqEventPlayTrack_2515e0 : public SeqEvent_2515e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventPlayTrack_2515e0* vfunc_4(unsigned char);
    virtual void v5();
};
class A_2515e0 {
  public:
    void f();
};
struct SeqEventPlayTrack_nv_2515e0 {
    void f();
};
void __cdecl f47550(void*, SeqEventPlayTrack_2515e0*);
SeqEventPlayTrack_2515e0* SeqEventPlayTrack_2515e0::vfunc_4(unsigned char flag) {
    ((A_2515e0*)((char*)this + 0x14))->f();
    ((SeqEventPlayTrack_nv_2515e0*)(((audio::SeqEventPlayTrack*)this)))->f();
    if (flag & 1)
        f47550(((char*)((char*)&DAT_004e6bc8 + 176)), this);
    return this;
}