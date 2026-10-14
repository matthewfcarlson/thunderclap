extern "C" void _ReadWriteBarrier();
class Ref_297640 {
  public:
    virtual void a();
    virtual void b();
};
extern int vt_297640;
class VisibilityNode {
  public:
    virtual void f0();
    virtual void f1();
    virtual VisibilityNode* vfunc_2(unsigned char);
    char pad[0x28];
    Ref_297640* member;
    void cleanup();
};
void thunk(VisibilityNode*);
VisibilityNode* VisibilityNode::vfunc_2(unsigned char flag) {
    *(void**)this = &vt_297640;
    _ReadWriteBarrier();
    if (member) {
        member->b();
        member = 0;
    }
    cleanup();
    if (flag & 1)
        thunk(this);
    return this;
}
