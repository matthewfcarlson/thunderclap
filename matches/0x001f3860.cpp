typedef unsigned char byte_1f3860;
extern void __cdecl release(void*);
extern void __cdecl destroy(void*);
extern int vtable_1f3860;
struct CSoundSequenceVoice {
    int* vf;
    void* m;
    CSoundSequenceVoice* FUN_001f3860(byte_1f3860);
};
CSoundSequenceVoice* CSoundSequenceVoice::FUN_001f3860(byte_1f3860 flags) {
    vf = &vtable_1f3860;
    if (m) {
        release(m);
        m = 0;
    }
    if (flags & 1)
        destroy(this);
    return this;
}