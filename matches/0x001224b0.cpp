typedef unsigned int U;
extern int g1;
extern int g2;
struct RoutTrack;
struct NewObj {
    U Init(RoutTrack*, U);
};
struct RoutTrack {
    virtual U f0();
    virtual U f1();
    virtual U f2();
    virtual U f3();
    virtual U f4();
    virtual U f5();
    virtual U f6();
    virtual U f7();
    virtual U f8();
    virtual U f9();
    virtual U vfunc_10(U, U, U);
};
extern int IsType(void*, int, int*, int*, int);
extern NewObj* Allocate(int);
U RoutTrack::vfunc_10(U a, U b, U c) {
    if (IsType((void*)c, 0, &g1, &g2, 0)) {
        NewObj* p = Allocate(0xb8);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}