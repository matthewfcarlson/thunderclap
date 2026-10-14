class Obj_265560 {
  public:
    virtual void f();
    virtual void g();
};
class Holder_265560 {
  public:
    int Count(Obj_265560*);
};
class C_265560 {
  public:
    char pad[0x0c];
    Holder_265560* m;
    void target(Obj_265560* p);
};
void C_265560::target(Obj_265560* p) {
    int n = m->Count(p);
    while (n > 0) {
        p->g();
        --n;
    }
}