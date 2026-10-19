class Caster_23d250 {
  public:
    virtual void Cast();
};
class Handler {
  public:
    void Set(void*);
};
extern void* __cdecl Find(void*, Caster_23d250*);
void __cdecl FUN_0023d250(Handler* h, void* p) {
    Caster_23d250 caster;
    void* v = Find(p, &caster);
    h->Set(v);
}