extern "C" void _ReadWriteBarrier();
extern void* vAction[];
extern void* vIRef[];
extern int DAT_004e5af0;
extern void FUN_00267090(void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct Target {
    void* vf;
    int p4;
    Ref* p8;
    Target* Dtor(unsigned char flag) throw();
};
Target* Target::Dtor(unsigned char flag) throw() {
    vf = vAction;
    _ReadWriteBarrier();
    if (p8) {
        p8->Release();
        p8 = 0;
    }
    DAT_004e5af0 = DAT_004e5af0 - 1;
    vf = vIRef;
    if (flag & 1)
        FUN_00267090(this);
    return this;
}
