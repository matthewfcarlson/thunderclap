class Item_302b70 {
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
    virtual bool Check(Item_302b70*, int);
    char pad[16];
    int value;
    unsigned char flag;
};
class Owner_302b70 {
  public:
    char pad[12];
    int field;
    void F(Item_302b70*, Item_302b70*);
    void Pair(Item_302b70*, Item_302b70*);
    void Order(Item_302b70*, Item_302b70*);
};
void Owner_302b70::F(Item_302b70* a, Item_302b70* b) {
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
