extern "C" char DAT_0049dba4[];
extern "C" char DAT_0049dbbc[];
class FEObject {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x();
    virtual void y();
    virtual void Set(int);
};
extern int __cdecl FindName(const char*);
extern int __cdecl LookupThing(int, int, int*, int*, int);
extern int __cdecl GetFlagThing(int);
struct Result_b5b90 {
    char Check();
};
struct Ctx_b5b90 {
    Result_b5b90* Get(int);
};
struct Global_b5b90 {
    char pad[0x54];
    Ctx_b5b90* ctx;
};
extern Global_b5b90* gGlobal_b5b90;
void FUN_000b5b90() {
    FEObject* p = (FEObject*)LookupThing(FindName("cheat_invulnerability_selector"), 0, (int*)((int)DAT_0049dba4),
                                         (int*)((int)DAT_0049dbbc), 0);
    if (p) {
        Result_b5b90* r = gGlobal_b5b90->ctx->Get(0x2e4);
        int flag = r->Check() == 0;
        p->Set(flag);
    }
}
