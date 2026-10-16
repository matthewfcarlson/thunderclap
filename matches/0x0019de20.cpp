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
void func(Obj* obj, void* value) {
    fight::TrackFactoryCasterTemplate caster;
    void* found = Find(value, &caster);
    obj->Use(found);
}