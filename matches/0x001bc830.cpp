class Obj_1bc830 {
  public:
    virtual void Fn0();
    virtual void Release();
};

class Holder_1bc830 {
  public:
    int pad0;
    Obj_1bc830* a;
    Obj_1bc830* b;
    Obj_1bc830* c;
    Obj_1bc830* d;
    Obj_1bc830* e;
    Obj_1bc830* f;
    void Free();
};

void Holder_1bc830::Free() {
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
