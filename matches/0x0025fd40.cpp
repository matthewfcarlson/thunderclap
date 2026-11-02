typedef unsigned char u8_25fd40;
struct Buf_25fd40 {
    u8_25fd40 d[32];
    void init();
    void fini();
};
extern "C" u8_25fd40 __cdecl FUN_00263500(int, Buf_25fd40*);
namespace audio {
struct SeqEvent {
    virtual void vfunc_0();
    virtual u8_25fd40 vfunc_1(int);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
} // namespace audio
u8_25fd40 audio::SeqEvent::vfunc_1(int p) {
    Buf_25fd40 b;
    b.init();
    u8_25fd40 r = FUN_00263500(p, &b);
    b.fini();
    return r;
}
