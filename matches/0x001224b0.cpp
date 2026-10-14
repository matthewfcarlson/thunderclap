typedef unsigned int U_1224b0;
extern int g1_1224b0;
extern int g2_1224b0;
struct RoutTrack;
struct NewObj_1224b0 {
    U_1224b0 Init(RoutTrack*, U_1224b0);
};
struct RoutTrack {
    virtual U_1224b0 f0();
    virtual U_1224b0 f1();
    virtual U_1224b0 f2();
    virtual U_1224b0 f3();
    virtual U_1224b0 f4();
    virtual U_1224b0 f5();
    virtual U_1224b0 f6();
    virtual U_1224b0 f7();
    virtual U_1224b0 f8();
    virtual U_1224b0 f9();
    virtual U_1224b0 vfunc_10(U_1224b0, U_1224b0, U_1224b0);
};
extern int IsType(void*, int, int*, int*, int);
extern NewObj_1224b0* Allocate(int);
U_1224b0 RoutTrack::vfunc_10(U_1224b0 a, U_1224b0 b, U_1224b0 c) {
    if (IsType((void*)c, 0, &g1_1224b0, &g2_1224b0, 0)) {
        NewObj_1224b0* p = Allocate(0xb8);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}