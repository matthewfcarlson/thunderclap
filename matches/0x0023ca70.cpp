class Caster {
  public:
    virtual void dummy();
};
extern "C" void* __cdecl Find(void*, Caster*);
class Factory {
  public:
    void Do(void*);
};
void Func(Factory* f, void* p) {
    Caster c;
    f->Do(Find(p, &c));
}