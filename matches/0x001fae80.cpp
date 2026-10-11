extern "C" void _ReadWriteBarrier();
inline void* operator new(unsigned, void* p) throw() {
    return p;
}
extern void* vGDH[];
extern "C" void* __cdecl FUN_0008d690(unsigned int) throw();
struct Inner {
    Inner() throw();
};
struct Target {
    void* vf;
    Inner* p4;
    int p8, pc, p10, p14, p18, p1c, p20, p24, p28, p2c, p30;
    Target() throw();
};
Target::Target() throw() {
    vf = vGDH;
    void* m = FUN_0008d690(0x5110);
    Inner* i;
    if (m)
        i = new (m) Inner;
    else
        i = 0;
    p4 = i;
    _ReadWriteBarrier();
    p8 = 0;
    pc = 0;
    p10 = 0;
    p14 = 0;
    p18 = 0;
    p1c = 0;
    p20 = 0;
    p24 = 0;
    p28 = 0;
    p2c = 0;
    p30 = 0;
}
