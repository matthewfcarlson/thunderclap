class Sub {
  public:
    virtual void f0();
    virtual void f1();
};
class File {
  public:
    char pad0[4];
    Sub sub;
    char pad8[12];
    int value;
    int vfunc_22();
};
int File::vfunc_22() {
    Sub* p = &sub;
    p->f0();
    int r = value;
    p->f1();
    return r;
}
