class Obj {
  public:
    virtual void Fn0();
    virtual void Release();
};

class Holder {
  public:
    int pad0;
    Obj* a;
    Obj* b;
    Obj* c;
    Obj* d;
    Obj* e;
    Obj* f;
    void Free();
};

void Holder::Free() {
    if (f) {
        f->Release();
        f = 0;
    }
    if (e) {
        e->Release();
        e = 0;
    }
    if (d) {
        d->Release();
        d = 0;
    }
    if (c) {
        c->Release();
        c = 0;
    }
    if (b) {
        b->Release();
        b = 0;
    }
    if (a) {
        a->Release();
        a = 0;
    }
}
