class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
extern void* find(const char*, Caster*);
extern "C" void FUN_00113c30(Obj* obj, const char* name) {
    Caster c;
    void* p = find(name, &c);
    obj->set(p);
}