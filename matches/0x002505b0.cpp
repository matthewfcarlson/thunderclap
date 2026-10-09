typedef unsigned int u32;
namespace audio {
struct SeqAction {
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(void*, int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[4];
};
struct SeqActionWaitBeat : SeqAction {
    u32 m8;
    u32 mc;
    u32 m10;
    u32 m14;
    void vfunc_2(void*, int);
};
} // namespace audio
extern "C" void* __cdecl FUN_0024a390(u32, void*);
void audio::SeqActionWaitBeat::vfunc_2(void* param, int unused) {
    u32 value = *(u32*)((char*)param + 0x3c);
    void* result = FUN_0024a390(value, (char*)m8 + 0x10);
    m14 = (u32)result;
    if (result)
        m10 = *(u32*)((char*)result + 0x2c);
    mc = 2;
}