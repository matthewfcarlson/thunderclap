class TrackFactoryCasterTemplate_18b020 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Fn(void*);
};
void* Find(void*, TrackFactoryCasterTemplate_18b020*);
void Target(Receiver* receiver, void* name) {
    TrackFactoryCasterTemplate_18b020 caster;
    receiver->Fn(Find(name, &caster));
}