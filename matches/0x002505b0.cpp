#include "compat/ptr.h"
typedef unsigned int u32_2505b0;
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
    hulk_uintptr m8;
    u32_2505b0 mc;
    u32_2505b0 m10;
    hulk_uintptr m14;
    void vfunc_2(void*, int);
};
} // namespace audio
extern "C" void* __cdecl FUN_0024a390(u32_2505b0, void*);
void audio::SeqActionWaitBeat::vfunc_2(void* param, int unused) {
    u32_2505b0 value = *(u32_2505b0*)((char*)param + 0x3c);
    void* result = FUN_0024a390(value, (char*)m8 + 0x10);
    m14 = (hulk_uintptr)result;
    if (result)
        m10 = *(u32_2505b0*)((char*)result + 0x2c);
    mc = 2;
}