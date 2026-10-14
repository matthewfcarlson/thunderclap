typedef unsigned int uint_23ef40;
struct SpawnTrack {
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
    virtual uint_23ef40 vfunc_10(uint_23ef40, uint_23ef40, uint_23ef40);
};
struct Alloc_23ef40 {
    uint_23ef40 run(uint_23ef40, SpawnTrack*, uint_23ef40);
};
extern Alloc_23ef40* FUN_0008d690(uint_23ef40);
uint_23ef40 SpawnTrack::vfunc_10(uint_23ef40 a, uint_23ef40 b, uint_23ef40 c) {
    Alloc_23ef40* p = FUN_0008d690(0x58);
    if (p)
        return p->run(a, this, c);
    return 0;
}