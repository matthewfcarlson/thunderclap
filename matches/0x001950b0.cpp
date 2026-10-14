extern "C" char DAT_0041b3a8[];
struct Part_1950b0 {
    void init();
};
struct Part2_1950b0 {
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
    vt = (void*)((int)DAT_0041b3a8);
    ((Part_1950b0*)((char*)this + 0xa8))->init();
    ((Part2_1950b0*)((char*)this + 0x98))->init2();
    ((Part_1950b0*)((char*)this + 0x40))->init();
    baseInit();
    if (flag & 1)
        destroy(this);
    return this;
}
