class Item_296740 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k(int, int, int, int);
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o(void*);
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
};
class BranchNode {
    char pad[0x18];

  public:
    int count;
    Item_296740** items;
    void vfunc_18(Item_296740*);
};
void BranchNode::vfunc_18(Item_296740* item) {
    if (item) {
        Item_296740** slot = items + count;
        item->a();
        Item_296740* old = *slot;
        if (old)
            old->b();
        *slot = item;
        ++count;
        item->o(this);
        item->k(1, 2, 1, 1);
        item->k(1, 6, 2, 1);
    }
}