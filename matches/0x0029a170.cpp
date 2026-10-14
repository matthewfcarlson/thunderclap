class CompositeDrawable {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual int vfunc_4();
};
class Allocated_29a170 {
  public:
    int method(CompositeDrawable*);
};
extern Allocated_29a170* alloc(int);
int CompositeDrawable::vfunc_4() {
    Allocated_29a170* p = alloc(0x58);
    if (p)
        return p->method(this);
    return 0;
}