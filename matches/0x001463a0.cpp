class Caster {
  public:
    virtual void Cast();
};
struct Target {
    int Get(void*);
};
extern "C" void* __cdecl Find(void*, Caster*);
int F(Target* t, void* x) {
    Caster c;
    void* p = Find(x, &c);
    return t->Get(p);
}