class MetaEntity {
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
    void cleanup();
};
class Entity : public MetaEntity {};
class IRefCount {};
class ListenerEffectXBox : public Entity, public IRefCount {
  public:
    virtual void v0();
    virtual void v1();
    virtual ListenerEffectXBox* vfunc_2(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};
extern void __cdecl FUN_00247550(void*, void*);
extern char g_4e6468[];
ListenerEffectXBox* ListenerEffectXBox::vfunc_2(int flag) {
    cleanup();
    if (flag & 1)
        FUN_00247550(g_4e6468, this);
    return this;
}