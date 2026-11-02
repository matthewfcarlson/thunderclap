namespace fight {
class TrackFactoryCasterTemplate {
  public:
    virtual void Cast();
};
} // namespace fight
class Obj {
  public:
    void Use(void*);
};
void* Find(void*, fight::TrackFactoryCasterTemplate*);
extern "C" void FUN_0019de20(Obj* obj, void* value) {
    fight::TrackFactoryCasterTemplate caster;
    void* found = Find(value, &caster);
    obj->Use(found);
}