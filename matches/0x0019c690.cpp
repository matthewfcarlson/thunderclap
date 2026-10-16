class Caster {
  public:
    virtual void dummy();
};
class Obj {
  public:
    void Do(void*);
};
void* Cast(void*, Caster*);
void F(Obj* obj, void* p) {
    Caster c;
    obj->Do(Cast(p, &c));
}