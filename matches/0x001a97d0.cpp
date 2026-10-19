class Caster_1a97d0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Find(void*);
};
extern "C" void* FindTrack(void*, Caster_1a97d0*);
void FUN_001a97d0(Obj* obj, void* name) {
    Caster_1a97d0 caster;
    obj->Find(FindTrack(name, &caster));
}