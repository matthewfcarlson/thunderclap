class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void use(void*);
};
void* find(const char*, Caster*);
void FUN_0017d640(Obj* obj, const char* name) {
    Caster c;
    obj->use(find(name, &c));
}