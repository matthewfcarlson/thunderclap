class A_16cc0 {
  public:
    int Get(int);
};
class B_16cc0 {
  public:
    void Put(int);
};
class A2 {
  public:
    A_16cc0* Second();
};
class M_16cc0 {
  public:
    A2* First();
};
extern B_16cc0* __cdecl Make();
class CEffectStopAction {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void vfunc_4();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    char pad[0x18];
    M_16cc0* m;
    int* data;
};
void CEffectStopAction::vfunc_4() {
    A2* q = m->First();
    A_16cc0* a = q->Second();
    B_16cc0* c = Make();
    int lo = data[4];
    int hi = data[5];
    if (lo < 0 || hi <= lo || hi >= 32) {
        int v = a->Get(lo);
        c->Put(v);
        return;
    }
    while (lo <= hi) {
        int v = a->Get(lo);
        c->Put(v);
        ++lo;
    }
}