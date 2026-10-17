// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// audio::HalRsdFileStream::vfunc_0 @ 0x002632c0
namespace audio {
struct StreamHelper {};
struct HalRsdFileStream {
    virtual void vfunc_0();
    char pad04[0x1c - 4];
    int field1c;
    void* field20;
    char pad24[0x44 - 0x24];
    int field44;
};
}
// equiv-conv: FUN_0023fb00 ecx stack stack stack stack stack stack stack
void* __cdecl FUN_0023fb00(audio::StreamHelper*, void*, int, int, int, int, int, int);
void __cdecl thunk_FUN_002710d0(void**, void*, int, int, int, int, int, int);
void audio::HalRsdFileStream::vfunc_0() {
    if (field20 == 0) {
        int saved = field1c;
        audio::StreamHelper* helper = (audio::StreamHelper*)((char*)this + 4);
        void* result = FUN_0023fb00(helper, this, 0, 0, saved, 0, 1, 1);
        thunk_FUN_002710d0(&field20, result, 0, 0, saved, 0, 1, 1);
    }
    field44 = 1;
}