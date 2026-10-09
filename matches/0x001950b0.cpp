struct Part {
    void init();
};
struct Part2 {
    void init2();
};
void destroy(void*);
struct FireGroundShockwaveTrack {
    void* vt;
    char pad[0xa8 - 4];
    FireGroundShockwaveTrack* vfunc_5(unsigned char flag);
    void baseInit();
};
FireGroundShockwaveTrack* FireGroundShockwaveTrack::vfunc_5(unsigned char flag) {
    vt = (void*)0x41b3a8;
    ((Part*)((char*)this + 0xa8))->init();
    ((Part2*)((char*)this + 0x98))->init2();
    ((Part*)((char*)this + 0x40))->init();
    baseInit();
    if (flag & 1)
        destroy(this);
    return this;
}
