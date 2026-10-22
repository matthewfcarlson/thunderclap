class TrackFactoryCasterTemplate_1586a0 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Set(void*);
};
void* Find(void*, TrackFactoryCasterTemplate_1586a0*);
void Target(Receiver* receiver, void* value) {
    TrackFactoryCasterTemplate_1586a0 caster;
    receiver->Set(Find(value, &caster));
}