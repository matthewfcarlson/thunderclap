extern "C" char DAT_003fa248[];
struct A_5e120 {
    int x;
    void init();
};
struct B_5e120 {
    int x;
    void init();
};
struct C_5e120 {
    int x;
    void init();
};
void __cdecl FreeTrack(void* p);

struct COpportunityBallTrack {
    int vptr;
    char p0[0x14];
    A_5e120 a;
    char p1[0x18];
    B_5e120 b;
    char p2[8];
    C_5e120 c;
    void baseInit();
    COpportunityBallTrack* vfunc_5(unsigned char param);
};

COpportunityBallTrack* COpportunityBallTrack::vfunc_5(unsigned char param) {
    vptr = ((int)DAT_003fa248);
    c.init();
    b.init();
    a.init();
    baseInit();
    if (param & 1) {
        FreeTrack(this);
    }
    return this;
}
