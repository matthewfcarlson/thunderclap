class Visitor {
  public:
    virtual void a();
    virtual void b();
};
class DrawableCounter : public Visitor {
  public:
    int count;
    virtual bool vfunc_0(Visitor*);
    virtual void vfunc_1();
};
class Item_296290 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual int type();
};
bool DrawableCounter::vfunc_0(Visitor* p) {
    if (p && ((Item_296290*)p)->type() == 16)
        ++count;
    return true;
}