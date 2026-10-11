extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void a();
    virtual void b();
};
extern int vt;
class VisibilityNode {
  public:
    virtual void f0();
    virtual void f1();
    virtual VisibilityNode* vfunc_2(unsigned char);
    char pad[0x28];
    Ref* member;
    void cleanup();
};
void thunk(VisibilityNode*);
VisibilityNode* VisibilityNode::vfunc_2(unsigned char flag) {
    *(void**)this = &vt;
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
