class TrackFactoryCasterTemplate_146370 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern void* Find(const char*, TrackFactoryCasterTemplate_146370*);
void FUN_00146370(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_146370 caster;
    obj->Set(Find(name, &caster));
}