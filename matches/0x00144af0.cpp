extern "C" char DAT_0041306c[];
typedef unsigned int u32_144af0;
void* __cdecl Alloc(unsigned int);
struct SlowMotionAction {
    void init();
    char pad[0x1c];
    void* volatile owner;
};
struct Track {
    char pad[0x1c];
};
struct SlowMotionTrack : Track {
    void* vfunc_10(int, int, int);
};
void* SlowMotionTrack::vfunc_10(int a, int b, int c) {
    SlowMotionAction* p = (SlowMotionAction*)Alloc(0x28);
    if (p) {
        p->init();
        *(volatile u32_144af0*)p = ((int)DAT_0041306c);
        p->owner = 0;
        p->owner = this;
        return p;
    }
    return 0;
}
