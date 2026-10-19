class Caster_19c690 {
  public:
    virtual void dummy();
};
class Obj {
  public:
    void Do(void*);
};
void* Cast(void*, Caster_19c690*);
void F(Obj* obj, void* p) {
    Caster_19c690 c;
    obj->Do(Cast(p, &c));
}