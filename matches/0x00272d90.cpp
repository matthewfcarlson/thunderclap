extern "C" void _ReadWriteBarrier();
extern void* vDrive[];
extern void* vD4[];
extern void* vDc[];
extern void* vSafe[];
extern void* vBase[];
extern void* vIRef[];
extern unsigned DAT_004cdbb0;
extern void FUN_00266f00(unsigned, void*);
class Part_272d90 {
  public:
    void Fini() throw();
};
struct Target_272d90 {
    void* v0;
    void* v4;
    unsigned p8;
    void* vc;
    int pad;
    Part_272d90 part;
    Target_272d90* Dtor(unsigned char flag) throw();
};
Target_272d90* Target_272d90::Dtor(unsigned char flag) throw() {
    v0 = vDrive;
    v4 = vD4;
    vc = vDc;
    part.Fini();
    vc = vSafe;
    _ReadWriteBarrier();
    unsigned t = p8;
    DAT_004cdbb0 = t;
    v4 = vBase;
    v0 = vIRef;
    if (flag & 1)
        FUN_00266f00(DAT_004cdbb0, this);
    return this;
}
