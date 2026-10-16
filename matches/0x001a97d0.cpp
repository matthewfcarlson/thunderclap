class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Find(void*);
};
extern "C" void* FindTrack(void*, Caster*);
void FUN_001a97d0(Obj* obj, void* name) {
    Caster caster;
    obj->Find(FindTrack(name, &caster));
}