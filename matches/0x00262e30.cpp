typedef unsigned char u8;
namespace audio {
class HalStream {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
};
class HalRadicalAdpcmDecodeStream : public HalStream {
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual HalRadicalAdpcmDecodeStream* vfunc_13(u8);
};
} // namespace audio
extern char DAT_004e7b08[];
extern void __cdecl FUN_00247550(void*, audio::HalRadicalAdpcmDecodeStream*);
audio::HalRadicalAdpcmDecodeStream* audio::HalRadicalAdpcmDecodeStream::vfunc_13(u8 p) {
    *(void**)this = (void*)0x42adc0;
    ((audio::HalStream*)*(void**)((char*)this + 4))->f12();
    if (p & 1)
        FUN_00247550(DAT_004e7b08, this);
    return this;
}