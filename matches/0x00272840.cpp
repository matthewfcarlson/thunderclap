extern "C" void _ReadWriteBarrier();
extern void* vDrive[];
extern void* vD4[];
extern void* vDc[];
extern void* vSafe[];
extern void* vBase[];
extern void* vIRef[];
extern unsigned DAT_004cdbb0;
class Part_272840 {
  public:
    void Fini() throw();
};
struct Target_272840 {
    void* v0;
    void* v4;
    unsigned p8;
    void* vc;
    int pad;
    Part_272840 part;
    void Dtor() throw();
};
void Target_272840::Dtor() throw() {
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
}
