extern "C" void _ReadWriteBarrier();
extern void* vAction[];
extern void* vIRef[];
extern int DAT_004e5af0;
extern void FUN_00267090(void*);
class Ref_232700 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Target_232700 {
    void* vf;
    int p4;
    Ref_232700* p8;
    Target_232700* Dtor(unsigned char flag) throw();
};
Target_232700* Target_232700::Dtor(unsigned char flag) throw() {
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
