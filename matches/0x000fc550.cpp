class Target {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

class Elem {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Act(int a, int b, char c);
    virtual void v5();
    virtual void v6();
    virtual void Fin(int x);
    char pad[4];
    float f;
};

class Other {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Notify();
    char pad[0x54];
    Target* t;
};

extern "C" void* FUN_00344e74(void*, int, void*, void*, int);
extern const float gZero;

class Owner {
  public:
    char pad[0x14];
    Elem* items[1];
    char pad2[0x3c];
    int cur;
    void Fn(int a, int b, char c);
};

void Owner::Fn(int a, int b, char c) {
    if (cur == -1)
        return;
    if (c) {
        Elem* e = items[cur];
        if (e->f <= gZero) {
            Other* o = (Other*)FUN_00344e74(e, 0, (void*)0x4a19e0, (void*)0x4a19f8, 0);
            if (o) {
                Target* t = o->t;
                if (t)
                    t->v6();
            }
        }
    }
    items[cur]->Act(a, b, c);
    items[cur]->Fin(1);
}
