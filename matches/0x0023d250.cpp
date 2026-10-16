class Caster {
  public:
    virtual void Cast();
};
class Handler {
  public:
    void Set(void*);
};
extern void* __cdecl Find(void*, Caster*);
void __cdecl FUN_0023d250(Handler* h, void* p) {
    Caster caster;
    void* v = Find(p, &caster);
    h->Set(v);
}