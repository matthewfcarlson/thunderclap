class TrackFactoryCasterTemplate_139300 {
  public:
    virtual void Cast();
};
extern int __cdecl Find(int, TrackFactoryCasterTemplate_139300*);
class Owner {
  public:
    void Apply(int);
};
extern "C" void __cdecl FUN_00139300(Owner* owner, int id) {
    TrackFactoryCasterTemplate_139300 caster;
    int v = Find(id, &caster);
    owner->Apply(v);
}