struct PathTrack {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual int vfunc_10(int a, int b, void* p);
};
struct TypeDesc_123450 {
    int a;
    int b;
};
extern int TypeCheck(void*, int, const void*, const void*, int);
extern void* Alloc(unsigned int);
struct NewTrack {
    int run(PathTrack* t, void* p);
};
extern TypeDesc_123450 typeA_123450;
extern TypeDesc_123450 typeB_123450;
int PathTrack::vfunc_10(int a, int b, void* p) {
    if (TypeCheck(p, 0, &typeA_123450, &typeB_123450, 0)) {
        NewTrack* q = (NewTrack*)Alloc(0xf0);
        if (q)
            return q->run(this, p);
    }
    return 0;
}
