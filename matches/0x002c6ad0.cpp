class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class DisplayTraversal {
  public:
    volatile int vf;
    int p0, p1, p2, p3;
    Ref* volatile mRef;
    DisplayTraversal* F2(unsigned int);
};
extern void Destroy(DisplayTraversal*);
DisplayTraversal* DisplayTraversal::F2(unsigned int flags) {
    vf = 0x42ef74;
    Ref* r = mRef;
    if (r) {
        r->Release();
        mRef = 0;
    }
    vf = 0x3f6098;
    if (flags & 1)
        Destroy(this);
    return this;
}