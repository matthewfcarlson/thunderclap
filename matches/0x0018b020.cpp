class TrackFactoryCasterTemplate_18b020 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Fn(void*);
};
void* Find(void*, TrackFactoryCasterTemplate_18b020*);
extern "C" void FUN_0018b020(Receiver* receiver, void* name) {
    TrackFactoryCasterTemplate_18b020 caster;
    receiver->Fn(Find(name, &caster));
}