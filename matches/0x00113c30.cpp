class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
extern void* find(const char*, Caster*);
void func(Obj* obj, const char* name) {
    Caster c;
    void* p = find(name, &c);
    obj->set(p);
}