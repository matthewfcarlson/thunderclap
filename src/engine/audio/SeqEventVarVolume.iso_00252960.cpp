// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00252780..0x00252b30 (kind game, layer engine, confidence high), dominant class audio::SeqEventVarVolume
// (tree_prelude.h: not needed)


// 0x00252960 audio::SeqEventVarVolume::vfunc_4 (35 B): matches/0x00252960.cpp [isolated: no out-of-line definition (target defined in a class body); compile error C2555: 'fn_00252960::SeqEventVarVolume::vfunc_4': overriding virtual function return type differs and is not covariant from 'fn]
// sym: ?vfunc_4@SeqEventVarVolume@fn_f3cd7fd2@@UAEPAV12@E@Z
namespace fn_f3cd7fd2 {} using namespace fn_f3cd7fd2;
namespace fn_f3cd7fd2 {
extern void* hulk_at_004e6ed8;
void __cdecl FUN_00247550(void*, void*);
void __fastcall FUN_0025fd10(void*);
class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual class SeqEventVarVolume* vfunc_4(unsigned char flags);
    virtual void v5();
};
class SeqEventVarVolume : public SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual class SeqEventVarVolume* vfunc_4(unsigned char flags);
    virtual void v5();
};
class SeqEventVarVolume* SeqEventVarVolume::vfunc_4(unsigned char flags) {
    FUN_0025fd10((void*)(this));
    if (flags & 1)
        FUN_00247550(&hulk_at_004e6ed8, this);
    return this;
}
} // namespace fn_f3cd7fd2

