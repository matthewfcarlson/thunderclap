class Caster {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d();
};
extern "C" __int64 __cdecl lookup(void*, int, int);
class LoadInventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d(Caster*, __int64);
    int Load(void* p);
};
int LoadInventory::Load(void* p) {
    Caster caster;
    return d(&caster, lookup(p, 0, 0));
}