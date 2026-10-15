class Caster {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
extern "C" __int64 __cdecl lookup(void*, int, int);
class LoadInventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(Caster*, __int64);
    void Load(void* p);
};
void LoadInventory::Load(void* p) {
    Caster caster;
    d(&caster, lookup(p, 0, 0));
}