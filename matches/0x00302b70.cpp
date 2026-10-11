class Item {
  public:
    virtual void a();
    virtual void b();
    virtual int c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual int Compare();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual bool Check(Item*, int);
    char pad[16];
    int value;
    unsigned char flag;
};
class Owner {
  public:
    char pad[12];
    int field;
    void F(Item*, Item*);
    void Pair(Item*, Item*);
    void Order(Item*, Item*);
};
void Owner::F(Item* a, Item* b) {
    if (a->Check(b, field)) {
        if (!a->flag) {
            if (a->value)
                Pair(a, b);
        } else if (!b->flag) {
            if (b->value)
                Pair(b, a);
        } else if (a->Compare() == 1 || b->Compare() == 1)
            Pair(b, a);
        else {
            int x = a->Compare();
            int y = b->Compare();
            if (x > y)
                Order(a, b);
            else
                Order(b, a);
        }
    }
}
