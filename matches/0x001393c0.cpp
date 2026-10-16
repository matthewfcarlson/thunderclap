class Caster {
  public:
    virtual void cast();
};
class Manager {
  public:
    int get(void* p);
};
extern "C" void* first(void*, Caster*);
int __cdecl target(Manager* mgr, void* name) {
    Caster caster;
    void* p = first(name, &caster);
    return mgr->get(p);
}