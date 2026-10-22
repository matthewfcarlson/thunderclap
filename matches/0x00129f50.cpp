class TrackFactoryCasterTemplate_129f50 {
  public:
    virtual void Cast();
};
class Object {
  public:
    void Use(void*);
};
extern "C" void* Find(void*, TrackFactoryCasterTemplate_129f50*);
void Target(Object* obj, void* name) {
    TrackFactoryCasterTemplate_129f50 caster;
    obj->Use(Find(name, &caster));
}
