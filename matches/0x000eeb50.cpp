class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
extern Ref* gRef;
class FEThingsBase {
  public:
    virtual void vfunc_65();
    char pad[0x17f8];
    Ref* member;
};
inline void clearRef(Ref*& p) {
    Ref* q = p;
    if (q) {
        q->Release();
        p = 0;
    }
}
void FEThingsBase::vfunc_65() {
    if (gRef) {
        gRef->Release();
        gRef = 0;
    }
    Ref* p = member;
    if (p) {
        clearRef(member);
        member = 0;
    }
}