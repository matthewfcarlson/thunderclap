class Inner {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
class File {
  public:
    char pad[12];
    Inner* p;
    void vfunc_26();
};
void File::vfunc_26() {
    p->f4();
}