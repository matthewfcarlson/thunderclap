namespace audio { struct OmHalStream { void** vf; char pad[0x1b8]; void vfunc_12(); }; }
extern int om_vftable;
struct Sub { void call(); };
extern void __cdecl FUN_00247550(void*, audio::OmHalStream*);
void audio::OmHalStream::vfunc_12() {
    if (this) {
        *(void**)this = &om_vftable;
        ((Sub*)((char*)this + 0x1bc))->call();
        FUN_00247550((void*)0x4e7808, this);
    }
}