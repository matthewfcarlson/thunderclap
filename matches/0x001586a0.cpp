class Caster_1586a0 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Set(void*);
};
void* Find(void*, Caster_1586a0*);
void Target(Receiver* receiver, void* value) {
    Caster_1586a0 caster;
    receiver->Set(Find(value, &caster));
}