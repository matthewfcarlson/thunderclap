class Caster_189f60 {
  public:
    virtual void cast();
};
class Obj {
  public:
    int Do(void*);
};
extern void* Find(int, Caster_189f60*);
int Func(Obj* obj, int name) {
    Caster_189f60 c;
    return obj->Do(Find(name, &c));
}