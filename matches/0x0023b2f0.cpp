class Obj {
  public:
    virtual void f0();
    virtual void f1();
};
extern void thunk(void*);
class IFileStringReader {
  public:
    unsigned int vt;
    unsigned int pad;
    Obj* sub;
    IFileStringReader* vfunc_2(int);
};
IFileStringReader* IFileStringReader::vfunc_2(int flag) {
    Obj* p = sub;
    vt = 0x428590;
    p->f1();
    vt = 0x3f6098;
    if (flag & 1)
        thunk(this);
    return this;
}