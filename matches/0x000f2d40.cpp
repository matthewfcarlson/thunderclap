class Obj {
  public:
    virtual void F();
};
struct Caster {
    virtual void C();
};
class Manager {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual Obj* Create(const Caster&, unsigned long long);
};
extern Manager* gManager;
extern unsigned long long __cdecl GetArg(void*);
class Owner {
    char pad[0x9a4];

  public:
    Obj* slots[4];
    void Run(void*);
};
void Owner::Run(void* p) {
    int i = 0;
    while (i < 4 && slots[i])
        ++i;
    if (i < 4) {
        Manager* m = gManager;
        unsigned long long a = GetArg(p);
        Obj* o = m->Create(Caster(), a);
        slots[i] = o;
        if (o)
            o->F();
    }
}
