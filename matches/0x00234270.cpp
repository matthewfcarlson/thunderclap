class Param {
  public:
    virtual void* first(int);
    virtual bool vfunc_1(void*);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class Item_234270 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void apply(Param*, void*);
};
bool Param::vfunc_1(void* arg) {
    int i = 0;
    Item_234270* p;
    while ((p = (Item_234270*)first(i)) != 0) {
        p->apply(this, arg);
        ++i;
    }
    return true;
}