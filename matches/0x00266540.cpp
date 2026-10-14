// Same code shape as 0x00265560 (propagated; names are from that function)
class Obj_266540 {
  public:
    virtual void f();
    virtual void g();
};
class Holder_266540 {
  public:
    int Count(Obj_266540*);
};
class C_266540 {
  public:
    char pad[0x0c];
    Holder_266540* m;
    void target(Obj_266540* p);
};
void C_266540::target(Obj_266540* p) {
    int n = m->Count(p);
    while (n > 0) {
        p->g();
        --n;
    }
}