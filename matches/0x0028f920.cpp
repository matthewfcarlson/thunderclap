class Obj_28f920 {
  public:
    virtual void A();
    virtual void B();
};
void thunk(int);
class Owner_28f920 {
  public:
    char first[4];
    int value;
    char pad[0xd8];
    Obj_28f920* m0;
    Obj_28f920* m1;
    Obj_28f920* m2;
    void cleanup();
};
void Owner_28f920::cleanup() {
    Obj_28f920* p;
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