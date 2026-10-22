class TrackFactoryCaster_12de00 {
  public:
    virtual void Cast();
};
class TrackFactoryCasterTemplate_12de00 : public TrackFactoryCaster_12de00 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Use(void*);
};
void* __cdecl Find(void*, TrackFactoryCaster_12de00*);
void __cdecl Target(Obj* obj, void* key) {
    TrackFactoryCasterTemplate_12de00 caster;
    obj->Use(Find(key, &caster));
}