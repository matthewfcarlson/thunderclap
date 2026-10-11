extern "C" char DAT_004e7808[];
namespace audio {
struct OmHalStream {
    void** vf;
    char pad[0x1b8];
    void vfunc_12();
};
} // namespace audio
extern int om_vftable;
struct Sub {
    void call();
};
extern void __cdecl FUN_00247550(void*, audio::OmHalStream*);
void audio::OmHalStream::vfunc_12() {
    if (this) {
        *(void**)this = &om_vftable;
        ((Sub*)((char*)this + 0x1bc))->call();
        FUN_00247550((void*)((int)DAT_004e7808), this);
    }
}