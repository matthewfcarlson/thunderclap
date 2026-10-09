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
struct TypeDesc {
    int a;
    int b;
};
extern int TypeCheck(void*, int, const void*, const void*, int);
extern void* Alloc(unsigned int);
struct NewTrack {
    int run(PathTrack* t, void* p);
};
extern TypeDesc typeA;
extern TypeDesc typeB;
int PathTrack::vfunc_10(int a, int b, void* p) {
    if (TypeCheck(p, 0, &typeA, &typeB, 0)) {
        NewTrack* q = (NewTrack*)Alloc(0xf0);
        if (q)
            return q->run(this, p);
    }
    return 0;
}
