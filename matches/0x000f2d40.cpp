class Obj_f2d40 {
  public:
    virtual void F();
};
struct DynamicCaster_f2d40 {
    virtual void C();
};
class Manager_f2d40 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual Obj_f2d40* Create(const DynamicCaster_f2d40&, unsigned long long);
};
extern Manager_f2d40* gManager_f2d40;
extern unsigned long long __cdecl GetArg(void*);
class Owner_f2d40 {
    char pad[0x9a4];

  public:
    Obj_f2d40* slots[4];
    void Run(void*);
};
void Owner_f2d40::Run(void* p) {
    int i = 0;
    while (i < 4 && slots[i])
        ++i;
    if (i < 4) {
        Manager_f2d40* m = gManager_f2d40;
        unsigned long long a = GetArg(p);
        Obj_f2d40* o = m->Create(DynamicCaster_f2d40(), a);
        slots[i] = o;
        if (o)
            o->F();
    }
}
