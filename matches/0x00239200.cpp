class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
void* find(const char*, Caster*);
void func(Obj* obj, const char* name) {
    Caster caster;
    void* p = find(name, &caster);
    obj->set(p);
}