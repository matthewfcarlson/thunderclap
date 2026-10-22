class TrackFactoryCasterTemplate_163760 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Use(void*);
};
void* Find(void*, TrackFactoryCasterTemplate_163760*);
void Target(Receiver* receiver, void* value) {
    TrackFactoryCasterTemplate_163760 caster;
    void* result = Find(value, &caster);
    receiver->Use(result);
}