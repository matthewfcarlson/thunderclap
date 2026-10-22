extern "C" void _ReadWriteBarrier();
inline void* operator new(unsigned, void* p) throw() {
    return p;
}
extern void* vGDH[];
extern "C" void* __cdecl FUN_0008d690(unsigned int) throw();
struct Inner_1fae80 {
    Inner_1fae80() throw();
};
struct CGameDataHandler_1fae80 {
    void* vf;
    Inner_1fae80* p4;
    int p8, pc, p10, p14, p18, p1c, p20, p24, p28, p2c, p30;
    CGameDataHandler_1fae80() throw();
};
CGameDataHandler_1fae80::CGameDataHandler_1fae80() throw() {
    vf = vGDH;
    void* m = FUN_0008d690(0x5110);
    Inner_1fae80* i;
    if (m)
        i = new (m) Inner_1fae80;
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
