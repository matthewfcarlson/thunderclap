class Obj {
  public:
    virtual void A();
    virtual void B();
};
void thunk(int);
class Owner {
  public:
    char first[4];
    int value;
    char pad[0xd8];
    Obj* m0;
    Obj* m1;
    Obj* m2;
    void cleanup();
};
void Owner::cleanup() {
    Obj* p;
    p = m1;
    if (p) {
        m1 = 0;
        p->B();
    }
    p = m2;
    if (p) {
        m2 = 0;
        p->B();
    }
    p = m0;
    if (p) {
        m0 = 0;
        p->B();
    }
    thunk(value);
}