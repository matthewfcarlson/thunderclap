class pddiObject {
  public:
    virtual void f0();
    virtual void vfunc_1();
    virtual void f2();
    virtual void vfunc_3(int);
    int mRefCount;
};
void pddiObject::vfunc_1() {
    if (--mRefCount < 1)
        vfunc_3(1);
}