class Ref {
  public:
    virtual void A();
    virtual void Release();
};
class Owner {
  public:
    Ref* a;
    char pad[8];
    Ref* b;
    Ref* c;
    Ref* d;
    Ref* e;
    void Clear();
};
extern int gValue;
void Owner::Clear() {
    if (a) {
        a->Release();
        a = 0;
    }
    if (b) {
        b->Release();
        b = 0;
    }
    if (c) {
        c->Release();
        c = 0;
    }
    if (d) {
        d->Release();
        d = 0;
    }
    if (e) {
        e->Release();
        e = 0;
    }
    gValue = 0;
}