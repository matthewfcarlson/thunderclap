struct Mat {
    char d[64];
    void Init();
};
void* Alloc(unsigned n);
class Base {
  public:
    Base() { a = 0; }
    virtual void f0();
    int a;
};
class BoneMatrixList : public Base {
  public:
    BoneMatrixList(unsigned n);
    virtual void f0();
    Mat* b;
    Mat* c;
};
BoneMatrixList::BoneMatrixList(unsigned n) {
    if (n > 0) {
        b = (Mat*)Alloc(n * 64);
        if (b) {
            c = b + n;
            goto L;
        }
    }
    b = 0;
    c = 0;
L:
    for (unsigned i = 0; i < n; i++)
        b[i].Init();
}
