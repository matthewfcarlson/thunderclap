class TrackFactoryCasterTemplate_139300 {
  public:
    virtual void Cast();
};
extern int __cdecl Find(int, TrackFactoryCasterTemplate_139300*);
class Owner {
  public:
    void Apply(int);
};
void __cdecl Target(Owner* owner, int id) {
    TrackFactoryCasterTemplate_139300 caster;
    int v = Find(id, &caster);
    owner->Apply(v);
}