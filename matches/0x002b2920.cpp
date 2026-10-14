// Same code shape as 0x0029a170 (propagated; names are from that function)
class CompositeDrawable {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual int vfunc_4();
};
class Allocated_2b2920 {
  public:
    int method(CompositeDrawable*);
};
extern Allocated_2b2920* alloc(int);
int CompositeDrawable::vfunc_4() {
    Allocated_2b2920* p = alloc(0x58);
    if (p)
        return p->method(this);
    return 0;
}