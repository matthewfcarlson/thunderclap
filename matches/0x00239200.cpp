class Caster_239200 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
void* find(const char*, Caster_239200*);
void func(Obj* obj, const char* name) {
    Caster_239200 caster;
    void* p = find(name, &caster);
    obj->set(p);
}