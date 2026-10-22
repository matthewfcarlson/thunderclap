struct Params {
    virtual void f();
};
struct Ent_124540 {
    char p[0x328];
    int target;
};
struct Holder_124540 {};
struct Condition_124540 {
    virtual void a();
};
struct Base2 {
    virtual void b();
};
class HasTargetCondition : public Condition_124540, public Base2 {
  public:
    char pad[4];
    bool mWant;
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool v6(int a, Params* p, int b);
};
extern "C" void* __cdecl DynCast(void*, int, void*, void*, int);
struct T1 {
    virtual void f();
};
struct T2 {
    virtual void f();
};
extern T1 t1_124540;
extern T2 t2;
Holder_124540* __fastcall G1(Params*);
Ent_124540* __fastcall G2(Holder_124540*);
bool HasTargetCondition::v6(int a, Params* p, int b) {
    if (!DynCast(p, 0, &t1_124540, &t2, 0))
        return false;
    int t = G2(G1(p))->target;
    if (mWant)
        return t != 0;
    return t == 0;
}