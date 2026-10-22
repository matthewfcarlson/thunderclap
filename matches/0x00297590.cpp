extern "C" void _ReadWriteBarrier();
extern int vt1_297590;
class Ref_297590 {
  public:
    virtual void f0();
    virtual void Release();
};
class BranchNode_297590 {
  public:
    void* vptr;
    ~BranchNode_297590() throw();
};
class VisibilityNode_297590 : public BranchNode_297590 {
  public:
    char p2c[40];
    Ref_297590* a2c;
    ~VisibilityNode_297590() throw();
};
VisibilityNode_297590::~VisibilityNode_297590() throw() {
    vptr = &vt1_297590;
    _ReadWriteBarrier();
    if (a2c) {
        a2c->Release();
        a2c = 0;
    }
}
