typedef unsigned int u32;
struct FireBeamTrack {
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
    virtual int f10(u32 a, u32 b, void* p);
};
extern int __cdecl Check(void*, int, const void*, const void*, int);
extern void* __cdecl Alloc(unsigned int);
struct NewThing {
    int Init(FireBeamTrack*, void*);
};
extern int rttiA;
extern int rttiB;
int FireBeamTrack::f10(u32 a, u32 b, void* p) {
    if (Check(p, 0, &rttiA, &rttiB, 0)) {
        NewThing* q = (NewThing*)Alloc(0x98);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}