class Item_1a8cb0 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_1a8cb0 {
  public:
    char pad[4];
    Item_1a8cb0* a;
    Item_1a8cb0* b;
    Item_1a8cb0* c;
    Item_1a8cb0* d;
    Item_1a8cb0* e;
    void Init();
    void Clear();
};
void Obj_1a8cb0::Clear() {
    Init();
    if (a) {
        a->B();
        a = 0;
    }
    if (b) {
        b->B();
        b = 0;
    }
    if (c) {
        c->B();
        c = 0;
    }
    if (d) {
        d->B();
        d = 0;
    }
    if (e) {
        e->B();
        e = 0;
    }
}