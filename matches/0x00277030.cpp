// Same code shape as 0x002762d0 (propagated; names are from that function)
class Inner_277030 {
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
    Inner_277030* p;
    void vfunc_26();
};
void File::vfunc_26() {
    p->f4();
}