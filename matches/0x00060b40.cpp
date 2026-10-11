extern "C" char DAT_003faa80[];
typedef unsigned char byte;
struct Part {
    void init();
};
struct CEffectTrack {
    unsigned long vf;
    char p4[20];
    Part a18;
    char p1c[15];
    Part a28;
    char p2c[7];
    Part a30;
    CEffectTrack* vfunc_5(byte);
    void helper();
};
extern void cleanup(CEffectTrack*);
CEffectTrack* CEffectTrack::vfunc_5(byte param_2) {
    vf = ((int)DAT_003faa80);
    a30.init();
    a28.init();
    a18.init();
    helper();
    if (param_2 & 1)
        cleanup(this);
    return this;
}